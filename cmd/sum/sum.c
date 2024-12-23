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
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#pragma ident	"%Z%%M%	%I%	%E% SMI"
/*
 * Sum bytes in file mod 2^16
 */


#define	WDMSK 0177777L
#define	BUFSIZE 512
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static void usage(void);

struct part {
	short unsigned hi, lo;
};

main(argc, argv)
int argc;
char **argv;
{
	int		ca;
	int		i		= 0;
	int		alg		= 0;
	int		errflg		= 0;
	int		c;
	FILE		*f;
	long long	nbytes;
	unsigned int	sum;
	unsigned int	lsavhi;
	unsigned int	lsavlo;

	union hilo { /* this only works right in case short is 1/2 of long */
		struct part hl;
		long	lg;
	} tempa, suma;

	(void) setlocale(LC_ALL, "");

	while ((c = getopt(argc, argv, "r")) != EOF)
		switch (c) {
		case 'r':
			alg = 1;
			break;
		case '?':
			usage();
		}

	argc -= optind;
	argv  = &argv[optind];

	do {
		if (i < argc) {
			if ((f = fopen(argv[i], "r")) == NULL) {
				(void) fprintf(stderr, "sum: %s ", argv[i]);
				perror("");
				errflg += 10;
				continue;
			}
		} else
			f = stdin;
		sum = 0;
		suma.lg = 0;
		nbytes = 0;
		if (alg == 1) {
			while ((c = getc(f)) != EOF) {
				nbytes++;
				if (sum & 01)
					sum = (sum >> 1) + 0x8000;
				else
					sum >>= 1;
				sum += c;
				sum &= 0xFFFF;
			}
		} else {
			while ((ca = getc(f)) != EOF) {
				nbytes++;
				suma.lg += ca & WDMSK;
			}
		}
		if (ferror(f)) {
			errflg++;
			(void) fprintf(stderr, "sum: read error on %s\n",
			    (argc > 0) ? argv[i] : "-");
		}
		if (alg == 1)
			(void) printf("%.5u %6lld", sum,
			    (nbytes+BUFSIZE-1)/BUFSIZE);
		else {
			tempa.lg = (suma.hl.lo & WDMSK) + (suma.hl.hi & WDMSK);
			lsavhi = (unsigned)tempa.hl.hi;
			lsavlo = (unsigned)tempa.hl.lo;
			(void) printf("%u %lld", (unsigned)(lsavhi + lsavlo),
			    (nbytes+BUFSIZE-1)/BUFSIZE);
		}
		if (argc > 0)
			(void) printf(" %s",
			    (argv[i] == (char *)0) ? "" : argv[i]);
		(void) printf("\n");
		(void) fclose(f);
	} while (++i < argc);
	return (errflg);
}

static void
usage(void)
{
	(void) fprintf(stderr, "usage: sum [-r] [file...]\n");
	exit(2);
}
