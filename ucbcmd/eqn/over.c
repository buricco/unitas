/*-
 * Copyright (c) 1991 The Regents of the University of California.
 * All rights reserved.
 *
 * This module is believed to contain source code proprietary to AT&T.
 * Use and redistribution is subject to the Berkeley Software License
 * Agreement and your Software Agreement with AT&T (Western Electric).
 */

#ifndef lint
static char sccsid[] = "@(#)over.c	4.4 (Berkeley) 4/17/91";
#endif /* not lint */

# include "e.h"

boverb(p1, p2) int p1, p2; {
	int h, b, treg, d;

	treg = oalloc();
	yyval = p1;
#ifndef NEQN
	d = VERT((ps*6*3) / 10);	/* 0.3m */
	h = eht[p1] + eht[p2] + d;
#else
	d = VERT(1);
	h = eht[p1] + eht[p2];
#endif /* NEQN */
	b = eht[p2] - d;
	if(dbg)printf(".\tb:bob: S%d <- S%d over S%d; b=%d, h=%d\n", 
		yyval, p1, p2, b, h);
	nrwid(p1, ps, p1);
	nrwid(p2, ps, p2);
	printf(".nr %d \\n(%d\n", treg, p1);
	printf(".if \\n(%d>\\n(%d .nr %d \\n(%d\n", p2, treg, treg, p2);
#ifndef NEQN
	printf(".nr %d \\n(%d+\\s%d.5m\\s0\n", treg, treg, EFFPS(ps));
#endif /* NEQN */
	printf(".ds %d \\v'%du'\\h'\\n(%du-\\n(%du/2u'\\*(%d\\\n", 
		yyval, eht[p2]-ebase[p2]-d, treg, p2, p2);
	printf("\\h'-\\n(%du-\\n(%du/2u'\\v'%du'\\*(%d\\\n", 
#ifndef NEQN
		p2, p1, -(eht[p2]-ebase[p2]+d+ebase[p1]), p1);
	printf("\\h'-\\n(%du-\\n(%du/2u+.1m'\\v'%du'\\l'\\n(%du-.2m'\\h'.1m'\\v'%du'\n", 
		 treg, p1, ebase[p1]+d, treg, d);
#else
		p2, p1, -eht[p2]+ebase[p2]-ebase[p1], p1);
	printf("\\h'-\\n(%du-\\n(%du-2u/2u'\\v'%du'\\l'\\n(%du'\\v'%du'\n", 
		 treg, p1, ebase[p1], treg, d);
#endif /* NEQN */
	ebase[yyval] = b;
	eht[yyval] = h;
	lfont[yyval] = rfont[yyval] = 0;
	ofree(p2);
	ofree(treg);
}
