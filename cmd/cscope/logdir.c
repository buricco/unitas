/*===========================================================================
 Copyright (c) 1998-2000, The Santa Cruz Operation 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 *Redistributions of source code must retain the above copyright notice,
 this list of conditions and the following disclaimer.

 *Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 *Neither name of The Santa Cruz Operation nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission. 

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 DAMAGE. 
 =========================================================================*/

/*
 *	logdir()
 *
 *	This routine does not use the getpwent(3) library routine
 *	because the latter uses the stdio package.  The allocation of
 *	storage in this package destroys the integrity of the shell's
 *	storage allocation.
 */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define	BUFSIZ	160

static char const rcsid[] = "$Id$";

static char line[BUFSIZ+1];

static char *
field(p)
register char *p;
{
	while (*p && *p != ':')
		++p;
	if (*p) *p++ = 0;
	return(p);
}

char *
logdir(name)
char *name;
{
	register char	*p;
	register int	i, j;
	int	pwf;
	
	/* attempt to open the password file */
	if ((pwf = myopen("/etc/passwd", 0, 0)) == -1)
		return(0);
		
	/* find the matching password entry */
	do {
		/* get the next line in the password file */
		i = read(pwf, line, BUFSIZ);
		for (j = 0; j < i; j++)
			if (line[j] == '\n')
				break;
		/* return a null pointer if the whole file has been read */
		if (j >= i)
			return(0);
		line[++j] = 0;			/* terminate the line */
		(void) lseek(pwf, (long) (j - i), 1);	/* point at the next line */
		p = field(line);		/* get the logname */
	} while (*name != *line ||	/* fast pretest */
	    strcmp(name, line) != 0);
	(void) close(pwf);
	
	/* skip the intervening fields */
	p = field(p);
	p = field(p);
	p = field(p);
	p = field(p);
	
	/* return the login directory */
	(void) field(p);
	return(p);
}
