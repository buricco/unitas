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

/*	cscope - interactive C symbol or text cross-reference
 *
 *	command history
 */

#include "global.h"

static char const rcsid[] = "$Id$";

static	struct cmd *tail, *current;

/* add a cmd to the history list */
void
addcmd( f, s)
int f;		/* field number */
char *s;	/* command text */
{
	struct cmd *h;

	h = (struct cmd *) mymalloc(sizeof(struct cmd));
	if( tail) {
		tail->next = h;
		h->next = 0;
		h->prev = tail;
		tail = h;
	} else {
		tail = h;
		h->next = h->prev = 0;
	}
	h->field = f;
	h->text = stralloc( s);
	current = 0;
}

/* return previous history item */
struct cmd *
prevcmd()
{
	if( current) {
		if( current->prev)	/* stay on first item */
			return current = current->prev;
		else
			return current;
	} else if( tail)
		return current = tail;
	else 
		return (struct cmd *) 0;
}

/* return next history item */
struct cmd *
nextcmd()
{
	if( current) {
		if( current->next)	/* stay on first item */
			return current = current->next;
		else
			return current;
	} else 
		return (struct cmd *) 0;
}
/* reset current to tail */
void
resetcmd()
{
	current = 0;
}

struct cmd *
currentcmd()
{
	return current;
}
