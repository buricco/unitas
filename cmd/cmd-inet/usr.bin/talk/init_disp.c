/*-
 * Copyright (c) 1983, 1985
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
static char sccsid[] = "@(#)init_disp.c	5.1 (Berkeley) 6/6/85";
#endif /* not lint */

/*
 * Initialization code for the display package,
 * as well as the signal handling routines.
 */

#define USE_OLD_TTY
#include "talk.h"
#include <sgtty.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>

void	sig_sent();

/* 
 * Set up curses, catch the appropriate signals,
 * and build the various windows.
 */
void
init_display()
{
	initscr();
	curses_initialized = 1;

	clear();
	refresh();

	noecho();
	crmode();

	signal(SIGINT, sig_sent);
	signal(SIGPIPE, sig_sent);

	/* curses takes care of ^Z */

	my_win.x_nlines = LINES / 2;
	my_win.x_ncols = COLS;
	my_win.x_win = newwin(my_win.x_nlines, my_win.x_ncols, 0, 0);
	scrollok(my_win.x_win, FALSE);
	wclear(my_win.x_win);

	his_win.x_nlines = LINES / 2 - 1;
	his_win.x_ncols = COLS;
	his_win.x_win = newwin(his_win.x_nlines, his_win.x_ncols,
	    my_win.x_nlines+1, 0);
	scrollok(his_win.x_win, FALSE);
	wclear(his_win.x_win);

	line_win = newwin(1, COLS, my_win.x_nlines, 0);
	box(line_win, '-', '-');
	wrefresh(line_win);

	/* let them know we are working on it */

	current_state = "No connection yet";
}

/*
 * Trade edit characters with the other talk. By agreement
 * the first three characters each talk transmits after
 * connection are the three edit characters.
 */
void
set_edit_chars()
{
	char buf[3];
	int cc;

#if defined(__svr4__)||defined(__linux__)
    struct termios tty;

    ioctl(0, TCGETS, (struct termios *) &tty);
	
    buf[0] = my_win.cerase = tty.c_cc[VERASE]; /* for SVID should be VERSE */
    buf[1] = my_win.kill = tty.c_cc[VKILL];
    buf[2] = my_win.werase = tty.c_cc[VWERASE];/* for SVID should be VWERSE */
#else /* ! SYSV */
    struct sgttyb tty;
    struct ltchars ltc;

    gtty(0, &tty);

	ioctl(0, TIOCGETP, &tty);
    ioctl(0, TIOCGLTC, (struct sgttyb *) &ltc);
	
    my_win.cerase = tty.sg_erase;
    my_win.kill = tty.sg_kill;

    if (ltc.t_werasc == (char) -1) {
	my_win.werase = '\027';	 /* control W */
    } else {
	my_win.werase = ltc.t_werasc;
    }

    buf[0] = my_win.cerase;
    buf[1] = my_win.kill;
    buf[2] = my_win.werase;
#endif /* SYSV */

	cc = write(sockt, buf, sizeof(buf));
	if (cc != sizeof(buf) )
		p_error("Lost the connection");
	cc = read(sockt, buf, sizeof(buf));
	if (cc != sizeof(buf) )
		p_error("Lost the connection");
	his_win.cerase = buf[0];
	his_win.kill = buf[1];
	his_win.werase = buf[2];
}

void
sig_sent()
{

	message("Connection closing. Exiting");
	quit();
}

/*
 * All done talking...hang up the phone and reset terminal thingy's
 */
void
quit()
{

	if (curses_initialized) {
		wmove(his_win.x_win, his_win.x_nlines-1, 0);
		wclrtoeol(his_win.x_win);
		wrefresh(his_win.x_win);
		endwin();
	}
	if (invitation_waiting)
		send_delete();
	exit(0);
}
