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
/*	  All Rights Reserved	*/

/* Modifications copyright 2024 S. V. Nickolas */
/*	Portions Copyright (c) 1988,1996,1999 by Sun Microsystems, Inc. */
/*	All Rights Reserved.					*/

#ident	"%Z%%M%	%I%	%E% SMI"	/* SVr4.0 1.6	*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <sys/param.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

#define	DEFAULT_LINES	1000
#define	ONE_K		1024
#define	ONE_M		ONE_K*ONE_K
#ifndef	TRUE
#define	TRUE		1
#define	FALSE		0
#endif

static	void	Usage();
static	void	next_file_name();

static	char	*progname;
static	int	suffix_length = 2;

main(int argc, char **argv)
{
	long	line_count = 0;
	long	byte_count = 0;
	long	out;
	char	*fname = NULL;
	char	head[MAXPATHLEN];
	char	*output_file_name;
	char	*tail;
	char	*last;
	FILE	*in_file = NULL;
	FILE	*out_file = (FILE *)NULL;
	int	i;
	int	c;
	int	wc;
	int	output_file_open;
	struct	statvfs stbuf;
	int	opt;
	int	non_standard_line_count = FALSE;

	(void) setlocale(LC_ALL, "");

	progname = argv[0];

	/* check for explicit stdin "-" option */
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-") == 0) {
			in_file = stdin;
			while (i < argc) {
				argv[i] = argv[i + 1];

				/* a "-" before "--" is an error */
				if ((argv[i] != NULL) &&
				    (strcmp(argv[i], "--") == 0)) {
					Usage();
				}
				i++;
			}
			argc--;
		}
	}

	/* check for non-standard "-line-count" option */
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--") == 0)
			break;

		if ((argv[i][0] == '-') && isdigit(argv[i][1])) {
			if (strlen(&argv[i][1]) !=
			    strspn(&argv[i][1], "0123456789")) {
				(void) fprintf(stderr, "%s: Badly formed number\n", progname);
				Usage();
			}

			line_count = (long) strtol(&argv[i][1],
			    (char **)NULL, 10);

			non_standard_line_count = TRUE;
			while (i < argc) {
				argv[i] = argv[i + 1];
				i++;
			}
			argc--;
		}
	}

	/* get options */
	while ((opt = getopt(argc, argv, "a:b:l:")) != EOF) {
		switch (opt) {
		case 'a':
			if (strcmp(optarg, "--") == 0) {
				Usage();
			}
			suffix_length = (long) strtol(optarg,
					(char **)NULL, 10);
			if (suffix_length <= 0) {
				(void) fprintf(stderr, "%s: Invalid \"-a %s\" option\n",
				    progname, optarg);
				Usage();
			}
			break;

		case 'b':
			if (strcmp(optarg, "--") == 0) {
				Usage();
			}
			byte_count = (long) strtol(optarg,
					(char **)NULL, 10);
			if (*(optarg + strspn(optarg, "0123456789")) == 'k')
				byte_count *= ONE_K;
			if (*(optarg + strspn(optarg, "0123456789")) == 'm')
				byte_count *= ONE_M;
			break;

		case 'l':
			if (strcmp(optarg, "--") == 0) {
				Usage();
			}
			if (non_standard_line_count == TRUE) {
				Usage();
			}
			line_count = (long) strtol(optarg,
					(char **)NULL, 10);
			break;

		default:
			Usage();
		}
	}

	/* get input file */
	if ((in_file == NULL) && (optind < argc)) {
		if ((in_file = fopen(argv[optind++], "r")) == NULL) {
			(void) perror("split");
			return (1);
		}
	}
	if (in_file == NULL) {
		in_file = stdin;
	}

	/* get output file name */
	if (optind < argc) {
		output_file_name = argv[optind];
		if ((tail = strrchr(output_file_name, '/')) == NULL) {
			tail = output_file_name;
			(void) getcwd(head, sizeof (head));
		} else {
			tail++;
			(void) strcpy(head, output_file_name);
			last = strrchr(head, '/');
			*++last = '\0';
		}

		if (statvfs(head, &stbuf) < 0) {
			perror(head);
			return (1);
		}

		if (strlen(tail) > (stbuf.f_namemax - suffix_length)) {
			(void) fprintf(stderr, "%s: More than %d characters in file name\n",
			    progname, stbuf.f_namemax - suffix_length);
			Usage();
		}
	} else
		output_file_name = "x";

	/* check options */
	if (((int) strlen(output_file_name) + suffix_length) > FILENAME_MAX) {
		(void) fprintf(stderr, "%s: Output file name too long\n", progname);
		return (1);
	}

	if (line_count && byte_count) {
		    Usage();
	}

	/* use default line count if none specified */
	if (line_count == 0) {
		line_count = DEFAULT_LINES;
	}

	/*
	 * allocate buffer for the filenames we'll construct; it must be
	 * big enough to hold the name in 'output_file_name' + an n-char
	 * suffix + NULL terminator
	 */
	if ((fname = (char *)malloc(strlen(output_file_name) +
	    suffix_length + 1)) == NULL) {
		(void) perror("split");
		return (1);
	}

	/* build first output file name */
	for (i = 0; output_file_name[i]; i++) {
		fname[i] = output_file_name[i];
	}
	while (i < (int) strlen(output_file_name) + suffix_length) {
		fname[i++] = 'a';
	}
	if (suffix_length)
		fname[i - 1] = 'a' - 1;
	fname[i] = '\0';

	for (; ; ) {
	    output_file_open = FALSE;
	    if (byte_count) {
		for (out = 0; out < byte_count; out++) {
		    errno = 0;
		    c = getc(in_file);
		    if (c == EOF) {
			if (errno != 0) {
			    int lerrno = errno;
			    (void) fprintf(stderr, "%s: Read error at file offset %lld: %s, "
				"aborting split\n",
				    progname, ftell(in_file),
				    strerror(lerrno));
			    if (output_file_open == TRUE)
				(void) fclose(out_file);
			    free(fname);
			    return (1);
			}
			if (output_file_open == TRUE)
			    (void) fclose(out_file);
			free(fname);
			return (0);
		    }
		    if (output_file_open == FALSE) {
			next_file_name(fname);
			if ((out_file = fopen(fname, "w")) == NULL) {
			    (void) perror("split");
			    free(fname);
			    return (1);
			}
			output_file_open = TRUE;
		    }
		    if (putc(c, out_file) == EOF) {
			perror("split");
			if (output_file_open == TRUE)
			    (void) fclose(out_file);
			free(fname);
			return (1);
		    }
		}
	    } else {
		for (out = 0; out < line_count; out++) {
		    do {
			errno = 0;
			wc = fgetc(in_file);
			if (wc == EOF) {
			    if (errno != 0) {
				if (errno == EILSEQ) {
				    (void) fprintf(stderr, "%s: Invalid multibyte sequence "
					"encountered at file offset %lld, "
					"aborting split\n",
					    progname, ftell(in_file));
				} else {
				    (void) perror("split");
				}
				if (output_file_open == TRUE)
				    (void) fclose(out_file);
				free(fname);
				return (1);
			    }
			    if (output_file_open == TRUE)
				(void) fclose(out_file);
			    free(fname);
			    return (0);
			}
			if (output_file_open == FALSE) {
			    next_file_name(fname);
			    if ((out_file = fopen(fname, "w")) == NULL) {
				(void) perror("split");
				free(fname);
				return (1);
			    }
			    output_file_open = TRUE;
			}
			if (fputc(wc, out_file) == EOF) {
			    (void) perror("split");
			    if (output_file_open == TRUE)
				(void) fclose(out_file);
			    free(fname);
			    return (1);
			}
		    } while (wc != '\n');
		}
	    }
	    if (output_file_open == TRUE)
		(void) fclose(out_file);
	}

	/*NOTREACHED*/
}


static	void
next_file_name(char * name)
{
	int	i;

	i = strlen(name) - 1;

	while (i >= (int)(strlen(name) - suffix_length)) {
		if (++name[i] <= 'z')
			return;
		name[i--] = 'a';
	}
	(void) fprintf(stderr, "%s: Exhausted output file names, aborting split\n",
		progname);
	exit(1);
}


static	void
Usage()
{
	(void) fprintf(stderr, "Usage: %s [-l #] [-a #] [file [name]]\n"
		"       %s [-b #[k|m]] [-a #] [file [name]]\n"
		"       %s [-#] [-a #] [file [name]]\n",
		progname, progname, progname);
	exit(1);
}
