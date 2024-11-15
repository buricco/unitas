/*-
 * This module is believed to contain source code proprietary to AT&T.
 * Use and redistribution is subject to the Berkeley Software License
 * Agreement and your Software Agreement with AT&T (Western Electric).
 */

#ifndef lint
static char sccsid[] = "@(#)tick.c	4.4 (Berkeley) 4/18/91";
#endif /* not lint */

/* time programs */
# include <stdio.h>
# include <sys/types.h>
# include <sys/timeb.h>
# include <time.h>
struct tbuffer {
	long	proc_user_time;
	long	proc_system_time;
	long	child_user_time;
	long	child_system_time;
};
static long start, user, tick_system;
tick()
{
	struct tbuffer tx;
	time_t tp;
	times (&tx);
	time (&tp);
	user =  tx.proc_user_time;
	tick_system= tx.proc_system_time;
	start = tp;
}
tock()
{
	struct tbuffer tx;
	time_t tp;
	float lap, use, sys;
	if (start==0) return;
	times (&tx);
	time (&tp);
	lap = (tp-start)/1000.;
	use = (tx.proc_user_time - user)/60.;
	sys = (tx.proc_system_time - tick_system)/60.;
	printf("Elapsed %.2f CPU %.2f (user %.2f, sys %.2f)\n",
		lap, use+sys, use, sys);
}
