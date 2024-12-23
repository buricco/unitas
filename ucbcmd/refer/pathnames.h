/*-
 * Copyright (c) 1989 The Regents of the University of California.
 * All rights reserved.
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
 *
 *	@(#)pathnames.h	5.5 (Berkeley) 7/20/92
 */

#ifdef __svr4__
#define _PATH_TMP "/tmp/"
#define _PATH_DEVNULL "/dev/null"
#define _PATH_TTY "/dev/tty"
#else
#include <paths.h>
#endif

#define	_PATH_ALL	"/usr/dict/lookall/All"
#define	_PATH_EIGN	"/usr/dict/eign"
#define	_PATH_HUNT	"/usr/old/libexec/hunt"
#define	_PATH_IND	"/usr/old/dict/papers/Ind"
#define	_PATH_LIB	"/usr/old/libexec"
#define	_PATH_MKEY	"/usr/old/libexec/mkey"
#define	_PATH_PWD	"/bin/pwd"
#define	_PATH_SORT	"/usr/bin/sort"
#define	_PATH_TMPS	"/tmp/SbibXXXXXX"
#define	_PATH_USRTMP	"/usr/tmp"
