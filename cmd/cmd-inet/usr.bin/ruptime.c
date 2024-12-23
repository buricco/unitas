/*
 * Copyright (c) 1983, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
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

#ifndef lint
static char copyright[] =
"@(#) Copyright (c) 1983, 1993, 1994\n\
	The Regents of the University of California.  All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)ruptime.c	8.2 (Berkeley) 4/5/94";
#endif /* not lint */

#include <sys/param.h>

#include <protocols/rwhod.h>

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tzfile.h>
#include <unistd.h>

#ifndef DAYSPERNYEAR
#define DAYSPERNYEAR DAYS_PER_NYEAR
#endif /* DAYSPERNYEAR */

#ifndef SECSPERDAY
#define SECSPERDAY SECS_PER_DAY
#endif /* SECSPERDAY */

#ifndef SECSPERMIN
#define SECSPERMIN SECS_PER_MIN
#endif /* SECSPERMIN */

#ifndef MINSPERHOUR
#define MINSPERHOUR MINS_PER_HOUR
#endif /* MINSPERHOUR */

#ifndef HOURSPERDAY
#define HOURSPERDAY HOURS_PER_DAY
#endif /* HOURSPERDAY */

#ifndef _PATH_RWHODIR
#define _PATH_RWHODIR "/var/spool/rwho"
#endif /* _PATH_RWHODIR */

struct hs {
	struct	whod *hs_wd;
	int	hs_nusers;
} *hs;
struct	whod awhod;

#define	ISDOWN(h)		(now - (h)->hs_wd->wd_recvtime > 11 * 60)
#define	WHDRSIZE	(sizeof (awhod) - sizeof (awhod.wd_we))

size_t nhosts;
time_t now;
int rflg = 1;

int	 hscmp (const void *, const void *);
char	*interval (time_t, char *);
int	 lcmp (const void *, const void *);
void	 morehosts (void);
int	 tcmp (const void *, const void *);
int	 ucmp (const void *, const void *);
void	 usage (void);

int
main(argc, argv)
	int argc;
	char **argv;
{
	extern int optind;
	struct dirent *dp;
	struct hs *hsp;
	struct whod *wd;
	struct whoent *we;
	DIR *dirp;
	size_t hspace;
	int aflg, cc, ch, fd, i, maxloadav;
	char buf[sizeof(struct whod)];
	int (*cmp) (const void *, const void *);

	aflg = 0;
	cmp = hscmp;
	while ((ch = getopt(argc, argv, "alrut")) != EOF)
		switch (ch) {
		case 'a':
			aflg = 1;
			break;
		case 'l':
			cmp = lcmp;
			break;
		case 'r':
			rflg = -1;
			break;
		case 't':
			cmp = tcmp;
			break;
		case 'u':
			cmp = ucmp;
			break;
		default: 
			usage();
		}
	argc -= optind;
	argv += optind;

	if (argc != 0)
		usage();

	if (chdir(_PATH_RWHODIR) || (dirp = opendir(".")) == NULL)
	{
		perror(_PATH_RWHODIR);
		exit(1);
	}

	maxloadav = -1;
	for (nhosts = hspace = 0; (dp = readdir(dirp)) != NULL;) {
		if (dp->d_ino == 0 || strncmp(dp->d_name, "whod.", 5))
			continue;
		if ((fd = open(dp->d_name, O_RDONLY, 0)) < 0) {
			perror(dp->d_name);
			continue;
		}
		cc = read(fd, buf, sizeof(struct whod));
		(void)close(fd);

		if (cc < WHDRSIZE)
			continue;
		if (nhosts == hspace) {
			if ((hs =
			    realloc(hs, (hspace += 40) * sizeof(*hs))) == NULL)
			{
				perror("ruptime");
				exit(1);
			}
			hsp = hs + nhosts;
		}

		if ((hsp->hs_wd = malloc((size_t)WHDRSIZE)) == NULL)
			{
				perror("ruptime");
				exit(1);
			}
		memmove(hsp->hs_wd, buf, (size_t)WHDRSIZE);

		for (wd = (struct whod *)buf, i = 0; i < 2; ++i)
			if (wd->wd_loadav[i] > maxloadav)
				maxloadav = wd->wd_loadav[i];

		for (hsp->hs_nusers = 0,
		    we = (struct whoent *)(buf + cc); --we >= wd->wd_we;)
			if (aflg || we->we_idle < 3600)
				++hsp->hs_nusers;
		++hsp;
		++nhosts;
	}
	if (nhosts == 0)
	{
		fprintf (stderr, "ruptime: no hosts in " _PATH_RWHODIR "\n");
		exit(0);
	}

	(void)time(&now);
	qsort(hs, nhosts, sizeof(hs[0]), cmp);
	for (i = 0; i < nhosts; i++) {
		hsp = &hs[i];
		if (ISDOWN(hsp)) {
			(void)printf("%-12.12s%s\n", hsp->hs_wd->wd_hostname,
			    interval(now - hsp->hs_wd->wd_recvtime, "down"));
			continue;
		}
		(void)printf(
		    "%-12.12s%s,  %4d user%s  load %*.2f, %*.2f, %*.2f\n",
		    hsp->hs_wd->wd_hostname,
		    interval((time_t)hsp->hs_wd->wd_sendtime -
			(time_t)hsp->hs_wd->wd_boottime, "  up"),
		    hsp->hs_nusers,
		    hsp->hs_nusers == 1 ? ", " : "s,",
		    maxloadav >= 1000 ? 5 : 4,
			hsp->hs_wd->wd_loadav[0] / 100.0,
		    maxloadav >= 1000 ? 5 : 4,
		        hsp->hs_wd->wd_loadav[1] / 100.0,
		    maxloadav >= 1000 ? 5 : 4,
		        hsp->hs_wd->wd_loadav[2] / 100.0);
	}
	exit(0);
}

char *
interval(tval, updown)
	time_t tval;
	char *updown;
{
	static char resbuf[32];
	int days, hours, minutes;

	if (tval < 0 || tval > DAYSPERNYEAR * SECSPERDAY) {
#ifdef __svr4__
		(void)sprintf(resbuf, "   %s ??:??", updown);
#else
		(void)snprintf(resbuf, sizeof(resbuf), "   %s ??:??", updown);
#endif
		return (resbuf);
	}
						/* round to minutes. */
	minutes = (tval + (SECSPERMIN - 1)) / SECSPERMIN;
	hours = minutes / MINSPERHOUR;
	minutes %= MINSPERHOUR;
	days = hours / HOURSPERDAY;
	hours %= HOURSPERDAY;
#ifdef __svr4__
	if (days)
		(void)sprintf(resbuf,
		    "%s %2d+%02d:%02d", updown, days, hours, minutes);
	else
		(void)sprintf(resbuf,
		    "%s    %2d:%02d", updown, hours, minutes);
#else
	if (days)
		(void)snprintf(resbuf, sizeof(resbuf),
		    "%s %2d+%02d:%02d", updown, days, hours, minutes);
	else
		(void)snprintf(resbuf, sizeof(resbuf),
		    "%s    %2d:%02d", updown, hours, minutes);
#endif
	return (resbuf);
}

#define	HS(a)	((struct hs *)(a))

/* Alphabetical comparison. */
int
hscmp(a1, a2)
	const void *a1, *a2;
{
	return (rflg *
	    strcmp(HS(a1)->hs_wd->wd_hostname, HS(a2)->hs_wd->wd_hostname));
}

/* Load average comparison. */
int
lcmp(a1, a2)
	const void *a1, *a2;
{
	if (ISDOWN(HS(a1)))
		if (ISDOWN(HS(a2)))
			return (tcmp(a1, a2));
		else
			return (rflg);
	else if (ISDOWN(HS(a2)))
		return (-rflg);
	else
		return (rflg *
		   (HS(a2)->hs_wd->wd_loadav[0] - HS(a1)->hs_wd->wd_loadav[0]));
}

/* Number of users comparison. */
int
ucmp(a1, a2)
	const void *a1, *a2;
{
	if (ISDOWN(HS(a1)))
		if (ISDOWN(HS(a2)))
			return (tcmp(a1, a2));
		else
			return (rflg);
	else if (ISDOWN(HS(a2)))
		return (-rflg);
	else
		return (rflg * (HS(a2)->hs_nusers - HS(a1)->hs_nusers));
}

/* Uptime comparison. */
int
tcmp(a1, a2)
	const void *a1, *a2;
{
	return (rflg * (
		(ISDOWN(HS(a2)) ? HS(a2)->hs_wd->wd_recvtime - now
		    : HS(a2)->hs_wd->wd_sendtime - HS(a2)->hs_wd->wd_boottime)
		-
		(ISDOWN(HS(a1)) ? HS(a1)->hs_wd->wd_recvtime - now
		    : HS(a1)->hs_wd->wd_sendtime - HS(a1)->hs_wd->wd_boottime)
	));
}

void
usage()
{
	(void)fprintf(stderr, "usage: ruptime [-alrut]\n");
	exit(1);
}
