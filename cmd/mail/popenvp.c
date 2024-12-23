/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/


/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	from OpenSolaris "popenvp.c	1.9	05/06/08 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)popenvp.c	1.6 (gritter) 6/22/05
 */
/*LINTLIBRARY*/

/*
 *  These routines are based on the standard UNIX stdio popen/pclose
 *  routines. This version takes an argv[][] argument instead of a string
 *  to be passed to the shell. The routine execvp() is used to call the
 *  program, hence the name popenvp() and the argument types.
 *
 *  This routine avoids an extra shell completely, along with not having
 *  to worry about quoting conventions in strings that have spaces,
 *  quotes, etc.
 */

#include <sys/types.h>
#include <assert.h>
#include <string.h>
#include "libmail.h"
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#include "sigset.h"

#define	tst(a, b) (*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1

#include <unistd.h>
static pid_t popen_pid[20];

/* Functions calling popenvp() should ensure 'file' is non-NULL */

FILE *
popenvp(char *file, char **argv, char *mode, int resetid)
{
	int	p[2];
	int myside, yourside;
	pid_t pid;

	assert(file != NULL);
	if (pipe(p) < 0)
		return (NULL);
	myside = tst(p[WTR], p[RDR]);
	yourside = tst(p[RDR], p[WTR]);
	if ((pid = fork()) == 0) {
		/* myside and yourside reverse roles in child */
		int	stdio;

		if (resetid) {
			setgid(getgid());
			setuid(getuid());
		}
		stdio = tst(0, 1);
		close(myside);
		close(stdio);
		fcntl(yourside, F_DUPFD, stdio);
		close(yourside);
		execvp(file, argv);
		fprintf(stderr, "exec of \"%s\" failed: %s\n",
		    file, strerror(errno));
		fflush(stderr);
		_exit(1);
	}
	if (pid == (pid_t)-1)
		return (NULL);
	popen_pid[myside] = pid;
	close(yourside);
	return (fdopen(myside, mode));
}

int
pclosevp(FILE *ptr)
{
	int f;
	pid_t r;
	int status;
	void (*hstat)(int), (*istat)(int), (*qstat)(int);

	f = fileno(ptr);
	fclose(ptr);
	istat = sigset(SIGINT, SIG_IGN);
	qstat = sigset(SIGQUIT, SIG_IGN);
	hstat = sigset(SIGHUP, SIG_IGN);
	do
		r = wait(&status);
	while (r != popen_pid[f] && r != (pid_t)-1);

	if (r == (pid_t)-1)
		status = -1;
	sigset(SIGINT, istat);
	sigset(SIGQUIT, qstat);
	sigset(SIGHUP, hstat);
	return (status);
}
