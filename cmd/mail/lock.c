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
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	from OpenSolaris "lock.c	1.7	05/06/08 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)lock.c	1.4 (gritter) 6/22/05
 */

#include "mail.h"

void
lock(char *user)
{
	char	tbuf[80];

	switch (maillock(user, 10)) {
	case L_SUCCESS:
	    return;
	case L_NAMELEN:
#if (defined(__sun))||(!defined(__svr4__))
	    snprintf(tbuf, sizeof (tbuf),
#else
	    sprintf(tbuf,
#endif
		"%s: Cannot create lock file. Username '%s' is > 13 chars\n",
		program, user);
	    break;
	case L_TMPLOCK:
	    strcpy(tbuf, "Cannot create temp lock file\n");
	    break;
	case L_TMPWRITE:
	    strcpy(tbuf, "Error writing pid to lock file\n");
	    break;
	case L_MAXTRYS:
	    strcpy(tbuf, "Creation of lockfile failed after 10 tries");
	    break;
	case L_ERROR:
	    strcpy(tbuf, "Cannot link temp lockfile to lockfile\n");
	    break;
	case L_MANLOCK:
	    strcpy(tbuf, "Cannot set mandatory file lock on temp lockfile\n");
	    break;
	}
	errmsg(E_LOCK, tbuf);
	if (sending) {
		goback(0);
	}
	done(0);
}

void 
unlock(void) {
	mailunlock();
}
