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

/* $Id$ */

/* library function return value declarations */

#if BSD
#define	strchr	index
#define strrchr	rindex
#undef	tolower		/* BSD toupper and tolower don't test the character */
#undef	toupper
#define	tolower(c)	(islower(c) ? (c) : (c) - 'A' + 'a')	
#define	toupper(c)	(isupper(c) ? (c) : (c) - 'a' + 'A')	
#endif

/* private library */
char	*basename(), *compath(), *egrepinit(), *logdir();
char	*mycalloc(), *mymalloc(), *myrealloc(), *stralloc();
FILE	*mypopen(), *vpfopen();
void	egrepcaseless();

/* standard C library */
char	*ctime(), *getcwd(), *getenv(), *mktemp();
char	*strcat(), *strcpy(), *strncpy(), *strpbrk(), *strchr(), *strrchr();
char	*strtok();
long	lseek(), time();
unsigned sleep();
void	exit(), free(), qsort();
#if BSD
FILE	*popen();	/* not in stdio.h */
#endif

/* Programmer's Workbench library (-lPW) */
char	*regcmp(), *regex();
