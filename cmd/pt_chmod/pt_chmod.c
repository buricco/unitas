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
 * Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T
 * Copyright (c) 2000, 2001 by Sun Microsystems, Inc.
 * Copyright (c) 2024 S. V. Nickolas.
 * All rights reserved.
 */


#ident	"%Z%%M%	%I%	%E% SMI"	/* SVr4.0 1.1	*/

#include <grp.h>
#include <stdlib.h>
#include <stropts.h>

/* Undocumented */
extern char *ptsname (int);

#define	DEFAULT_TTY_GROUP	"tty"

/*
 * 1) change the owner and mode of the pseudo terminal slave device.
 * 2) (re)create nodes and devlinks for pseduo terminal slave device.
 */
main(int argc, char **argv)
{
	int	fd;
	gid_t	gid;
	char	*tty;

	struct	group	*gr_name_ptr;

	if (argc > 2)
		exit(1);

	if ((gr_name_ptr = getgrnam(DEFAULT_TTY_GROUP)) != NULL)
		gid = gr_name_ptr->gr_gid;
	else
		gid = getgid();

	fd = atoi(argv[1]);

	tty = ptsname(fd);

	if (tty == NULL)
		exit(1);

	/*
	 * Detach all STREAMs.
	 * We need to continue to try this until we have succeeded
	 * in calling chown on the underlying node.  From that point
	 * onwards, no-one but root can fattach() as fattach() requires
	 * ownership of the node.
	 */
	do {
		if (chown(tty, 0, 0) != 0)
			exit(1);
	} while (fdetach(tty) == 0);

	if (chown(tty, getuid(), gid))
		exit(1);

	if (chmod(tty, 00620))
		exit(1);

	exit(0);
}
