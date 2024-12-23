/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Edward Sze-Tyan Wang.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Modifications copyright 2024 S. V. Nickolas
 */

#ifndef lint
static char sccsid[] = "@(#)reverse.c	8.1 (Berkeley) 6/6/93";
#endif /* not lint */

#include <sys/param.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

#ifdef __svr4__
#define SIZE_MAX INT_MAX
#else
#include <stdint.h>
#endif

static void r_buf (FILE *);
static void r_reg (FILE *, enum STYLE, long, struct stat *);

/*
 * reverse -- display input in reverse order by line.
 *
 * There are six separate cases for this -- regular and non-regular
 * files by bytes, lines or the whole file.
 *
 * BYTES	display N bytes
 *	REG	mmap the file and display the lines
 *	NOREG	cyclically read characters into a wrap-around buffer
 *
 * LINES	display N lines
 *	REG	mmap the file and display the lines
 *	NOREG	cyclically read lines into a wrap-around array of buffers
 *
 * FILE		display the entire file
 *	REG	mmap the file and display the lines
 *	NOREG	cyclically read input into a linked list of buffers
 */
void
reverse(fp, style, off, sbp)
	FILE *fp;
	enum STYLE style;
	long off;
	struct stat *sbp;
{
	if (style != REVERSE && off == 0)
		return;

	if (S_ISREG(sbp->st_mode))
		r_reg(fp, style, off, sbp);
	else
		switch(style) {
		case FBYTES:
		case RBYTES:
			bytes(fp, off);
			break;
		case FLINES:
		case RLINES:
			lines(fp, off);
			break;
		case REVERSE:
			r_buf(fp);
			break;
		}
}

/*
 * r_reg -- display a regular file in reverse order by line.
 */
static void
r_reg(fp, style, off, sbp)
	FILE *fp;
	register enum STYLE style;
	long off;
	struct stat *sbp;
{
	register off_t size;
	register int llen;
	register char *p;
	char *start;

	if (!(size = sbp->st_size))
		return;

	if (size > SIZE_MAX) {
		err(0, "%s: %s", fname, strerror(EFBIG));
		return;
	}

	if ((start = mmap(NULL, (size_t)size,
	    PROT_READ, 0, fileno(fp), (off_t)0)) == (caddr_t)-1) {
		err(0, "%s: %s", fname, strerror(EFBIG));
		return;
	}
	p = start + size - 1;

	if (style == RBYTES && off < size)
		size = off;

	/* Last char is special, ignore whether newline or not. */
	for (llen = 1; --size; ++llen)
		if (*--p == '\n') {
			WR(p + 1, llen);
			llen = 0;
			if (style == RLINES && !--off) {
				++p;
				break;
			}
		}
	if (llen)
		WR(p, llen);
	if (munmap(start, (size_t)sbp->st_size))
		err(0, "%s: %s", fname, strerror(errno));
}

typedef struct bf {
	struct bf *next;
	struct bf *prev;
	int len;
	char *l;
} BF;

/*
 * r_buf -- display a non-regular file in reverse order by line.
 *
 * This is the function that saves the entire input, storing the data in a
 * doubly linked list of buffers and then displays them in reverse order.
 * It has the usual nastiness of trying to find the newlines, as there's no
 * guarantee that a newline occurs anywhere in the file, let alone in any
 * particular buffer.  If we run out of memory, input is discarded (and the
 * user warned).
 */
static void
r_buf(fp)
	FILE *fp;
{
	register BF *mark, *tl, *tr;
	register int ch, len, llen;
	register char *p;
	off_t enomem;

#define	BSZ	(128 * 1024)
	for (mark = NULL, enomem = 0;;) {
		/*
		 * Allocate a new block and link it into place in a doubly
		 * linked list.  If out of memory, toss the LRU block and
		 * keep going.
		 */
		if (enomem || (tl = malloc(sizeof(BF))) == NULL ||
		    (tl->l = malloc(BSZ)) == NULL) {
			if (!mark)
				err(1, "%s", strerror(errno));
			tl = enomem ? tl->next : mark;
			enomem += tl->len;
		} else if (mark) {
			tl->next = mark;
			tl->prev = mark->prev;
			mark->prev->next = tl;
			mark->prev = tl;
		} else
			mark->next = mark->prev = (mark = tl);

		/* Fill the block with input data. */
		for (p = tl->l, len = 0;
		    len < BSZ && (ch = getc(fp)) != EOF; ++len)
			*p++ = ch;

		/*
		 * If no input data for this block and we tossed some data,
		 * recover it.
		 */
		if (!len) {
			if (enomem)
				enomem -= tl->len;
			tl = tl->prev;
			break;
		}

		tl->len = len;
		if (ch == EOF)
			break;
	}

	if (enomem) {
		(void)fprintf(stderr,
		    "tail: warning: %ld bytes discarded\n", enomem);
		rval = 1;
	}

	/*
	 * Step through the blocks in the reverse order read.  The last char
	 * is special, ignore whether newline or not.
	 */
	for (mark = tl;;) {
		for (p = tl->l + (len = tl->len) - 1, llen = 0; len--;
		    --p, ++llen)
			if (*p == '\n') {
				if (llen) {
					WR(p + 1, llen);
					llen = 0;
				}
				if (tl == mark)
					continue;
				for (tr = tl->next; tr->len; tr = tr->next) {
					WR(tr->l, tr->len);
					tr->len = 0;
					if (tr == mark)
						break;
				}
			}
		tl->len = llen;
		if ((tl = tl->prev) == mark)
			break;
	}
	tl = tl->next;
	if (tl->len) {
		WR(tl->l, tl->len);
		tl->len = 0;
	}
	while ((tl = tl->next)->len) {
		WR(tl->l, tl->len);
		tl->len = 0;
	}
}
