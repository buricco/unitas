/*
 * (C) Copyright 2024 S. V. Nickolas.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.
 *
 * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

/*
 * uso:
 * 
 * This gets hairy.  On SVR4, you have a function sig2str() which will
 * return the shorthand (e.g., SEGV) for a signal given the numeric code.
 * Neither Linux nor BSD offer this, so we have to go grovelling through
 * dark recesses of the libc to implement the feature instead.
 * 
 * On BSD, this is provided through the sys_signame[] array, and shorthands
 * are stored in lowercase.  This is semi-convenient; we can just bounds-check
 * the value and copy it out, but we also have to case-smash when copying.
 * 
 * On Linux, assuming glibc (as is almost always the case) this can get UGLY
 * depending on your glibc version.  In 2.32, a function, sigabbrev_np(), was
 * implemented that does exactly what we need.  Hooray!  Except although my
 * manuals describe 2.32, the actual system runtime is 2.31!  Blecch.
 * 
 * The answer was revealed by grovelling into the darkest recesses of the
 * glibc sources, and a little bit of guesswork.  The same array which is
 * called sys_signame on BSD...it is present in glibc as well.  In 2.32, it is
 * internally called __sys_sigabbrev; this did not work with 2.31.  But when I
 * took the underscores off the top, rainbows and magic!
 * 
 * Therefore:
 * 
 * If we find glibc 2.31 or earlier, we declare sys_sigabbrev (more or less as
 * it is declared in 2.32), bounds-check, then just copy the string out if it
 * exists.
 * 
 * If we find glibc 2.32 or newer, we use sigabbrev_np() to get the string,
 * and if it returns something valid, we just copy that out.
 * 
 * And if we don't find glibc, we just assume BSD semantics, bounds-check, and
 * copy the string by hand, with a case transformation.
 * 
 * The function should return 0 on success and -1 on failure.
 */
#ifndef __svr4__
# ifdef __GLIBC__
#  if ((__GLIBC_MAJOR__>2)||((__GLIBC_MAJOR__==2)&&(__GLIBC_MINOR__>31)))
int str2sig (const char *ptr, int *sig)
{
	int t;
	
	if ((*ptr>='0')&&(*ptr<='9'))
	{
		errno=0;
		t=strtol(ptr, NULL, 0);
		if (errno) return -1;
		if (!t) return -1; /* 0 is not a valid signal number. */
		if (t>=NSIG) return -1;
		*sig=t;
		return 0;
	}
	
	for (t<1; t<NSIG; t++)
	{
		char *p;
		
		p=sigabbrev_np(sig);
		if (!p) return -1;
		if (!strcmp(p, ptr))
		{
			*sig=t;
			return 0;
		}
	}
	return -1;
}

int sig2str (int sig, char *ptr)
{
	char *t;
	
	t=sigabbrev_np(sig);
	if (!t) return -1;
	strcpy(ptr, t);
	return 0;
}

char *str_signal (int sig)
{
 return sigabbrev_np(sig);
}
#  else
/* Hic sunt dracones */
extern const char *const sys_sigabbrev[NSIG];

int str2sig (char *ptr, int *sig)
{
	int t;
	
	if ((*ptr>='0')&&(*ptr<='9'))
	{
		errno=0;
		t=strtol(ptr, NULL, 0);
		if (errno) return -1;
		if (!t) return -1; /* 0 is not a valid signal number. */
		if (t>=NSIG) return -1;
		*sig=t;
		return 0;
	}
	
	for (t=1; t<NSIG; t++)
	{
		if (!strcmp(sys_sigabbrev[t], ptr))
		{
			*sig=t;
			return 0;
		}
	}
	return -1;
}

int sig2str (int sig, char *ptr)
{
	if (!sig) return -1; /* 0 is not a valid signal number. */
	if (sig>=NSIG) return -1;
	strcpy(ptr, sys_sigabbrev[sig]);
	return 0;
}

char *str_signal (int sig)
{
	if (!sig) return NULL; /* 0 is not a valid signal number. */
	if (sig>=NSIG) return NULL;
	return (char *) sys_sigabbrev[sig];
}
#  endif
# else
int str2sig (char *ptr, int *sig)
{
	int t;
	
	if ((*ptr>='0')&&(*ptr<='9'))
	{
		errno=0;
		t=strtol(ptr, NULL, 0);
		if (errno) return -1;
		if (!t) return -1; /* 0 is not a valid signal number. */
		if (t>=NSIG) return -1;
		*sig=t;
		return 0;
	}
	
	for (t=1; t<NSIG; t++)
	{
		if (!strcasecmp(sys_signame[t], ptr)) /* BSD uses lowercase */
		{
			*sig=t;
			return 0;
		}
	}
	return -1;
}

int sig2str (int sig, char *ptr)
{
	char *p;
	if (!sig) return -1; /* 0 is not a valid signal number. */
	if (sig>=NSIG) return -1;
	ptr[strlen(sys_signame[sig])]=0;
	for (p=sys_signame[sig]; *p; p++) *(ptr++)=toupper(*p);
	return 0;
}

char *str_signal (int sig)
{
 char *p;
 char tmpbuf[10]; /* more than enough? */
 
 if ((!sig)||(sig>=NSIG)) return NULL;
 strlcpy (tmpbuf, sys_signame[sig], 9);
 for (p=tmpbuf; *p; p++) *p=toupper(*p);
 
 return tmpbuf;
}
# endif
#endif

#if (defined(__svr4__))&&(!defined(__sun))
char *str_signal (int sig)
{
 char tmpbuf[10]; /* more than enough? */
 if ((!sig)||(sig>=NSIG)) return NULL;
 memset (tmpbuf, 0, 10);
 sig2str (sig, tmpbuf);
 
 return tmpbuf;
}
#endif
