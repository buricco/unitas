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
 * Copyright 1992 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */
#pragma ident	"%Z%%M%	%I%	%E% SMI"	/* SVr4.0 1.9   */
/*
 *	acctcon2 <ctmp >ctacct
 *	reads std. input (ctmp.h/ascii format)
 *	converts to tacct.h form, writes to std. output
 */

#include <sys/types.h>
#include "acctdef.h"
#include <stdio.h>

struct	ctmp	cb;
struct	tacct	tb;

main(argc, argv)
char **argv;
{
	tb.ta_sc = 1;
	while (scanf("%lu\t%ld\t%s\t%lu\t%lu\t%lu\t%*[^\n]",
		&cb.ct_tty,
		&cb.ct_uid,
		cb.ct_name,
		&cb.ct_con[0],
		&cb.ct_con[1],
		&cb.ct_start) != EOF) {

		tb.ta_uid = cb.ct_uid;
		CPYN(tb.ta_name, cb.ct_name);
		tb.ta_con[0] = MINS(cb.ct_con[0]);
		tb.ta_con[1] = MINS(cb.ct_con[1]);
		fwrite(&tb, sizeof (tb), 1, stdout);
	}
	exit(0);
}
