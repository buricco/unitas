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
/*
 * Modifications Copyright 2024 S. V. Nickolas
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/


#pragma ident	"%Z%%M%	%I%	%E% SMI"

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <unistd.h>
#include "usage.h"

#define	BADPID	(-2)

static char	*prog;
static char	*deflt = NULL, *error = NULL, *help = NULL, *prompt = NULL;
static int	kpid = BADPID;
static int	signo, disp;

static const char	eusage[] = "mWe";
static const char	husage[] = "mWh";

static int ckquit, ckwidth, ckindent;

static void
usage(void)
{
	switch (*prog) {
	default:
		(void) fprintf(stderr,
			"usage: %s [options] [-m]\n", prog);
		(void) fprintf(stderr, OPTMESG);
		(void) fprintf(stderr, STDOPTS);
		break;

	case 'd':
		(void) fprintf(stderr,
			"usage: %s\n", prog);
		break;

	case 'v':
		(void) fprintf(stderr,
			"usage: %s input\n", prog);
		break;

	case 'h':
		(void) fprintf(stderr,
			"usage: %s [options] [-m]\n", prog);
		(void) fprintf(stderr, OPTMESG);
		(void) fprintf(stderr,
			"\t-W width\n\t-h help\n");
		break;

	case 'e':
		(void) fprintf(stderr,
			"usage: %s [options] [-m]\n", prog);
		(void) fprintf(stderr, OPTMESG);
		(void) fprintf(stderr,
			"\t-W width\n\t-e error\n");
		break;
	}
	exit(1);
}

/*
 * Given argv[0], return a pointer to the basename of the program.
 */
static char *
prog_name(char *arg0)
{
	char *str;

	/* first strip trailing '/' characters (exec() allows these!) */
	str = arg0 + strlen(arg0);
	while (str > arg0 && *--str == '/')
		*str = '\0';
	if ((str = strrchr(arg0, '/')) != NULL)
		return (str + 1);
	return (arg0);
}

int
main(int argc, char **argv)
{
	int	c, n;
	char	*gid;
	size_t	len;

	(void) setlocale(LC_ALL, "");

	prog = prog_name(argv[0]);

	while ((c = getopt(argc, argv, "md:p:e:h:k:s:QW:?")) != EOF) {
		/* check for invalid option */
		if ((*prog == 'v') || (*prog == 'd'))
			usage(); /* no valid options */
		if ((*prog == 'e') && !strchr(eusage, c))
			usage();
		if ((*prog == 'h') && !strchr(husage, c))
			usage();

		switch (c) {
		case 'Q':
			ckquit = 0;
			break;

		case 'W':
			ckwidth = atoi(optarg);
			if (ckwidth < 0) {
				(void) fprintf(stderr,
		"%s: ERROR: negative display width specified\n",
					prog);
				exit(1);
			}
			break;

		case 'm':
			disp = 1;
			break;

		case 'd':
			deflt = optarg;
			break;

		case 'p':
			prompt = optarg;
			break;

		case 'e':
			error = optarg;
			break;

		case 'h':
			help = optarg;
			break;

		case 'k':
			kpid = atoi(optarg);
			break;

		case 's':
			signo = atoi(optarg);
			break;

		default:
			usage();
		}
	}

	if (signo) {
		if (kpid == BADPID)
			usage();
	} else
		signo = SIGTERM;

	if (*prog == 'v') {
		if (argc != (optind+1))
			usage();
		exit(ckgid_val(argv[optind]));
	}

	if (argc != optind)
		usage();


	if (*prog == 'e') {
		ckindent = 0;
		ckgid_err(disp, error);
		exit(0);
	} else if (*prog == 'h') {
		ckindent = 0;
		ckgid_hlp(disp, help);
		exit(0);
	} else if (*prog == 'd') {
		exit(ckgid_dsp());
	}

	if (deflt) {
		len = strlen(deflt) + 1;
		if (len < MAX_INPUT)
			len = MAX_INPUT;
	} else {
		len = MAX_INPUT;
	}
	gid = (char *)malloc(len);
	if (!gid) {
		(void) fprintf(stderr,
			"Not enough memory\n");
		exit(1);
	}
	n = ckgid(gid, disp, deflt, error, help, prompt);
	if (n == 3) {
		if (kpid > -2)
			(void) kill(kpid, signo);
		(void) puts("q");
	} else if (n == 0)
		(void) fputs(gid, stdout);
	return (n);
}
