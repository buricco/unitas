/*
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
 *	@(#)pathnames.h	5.6 (Berkeley) 3/4/91
 */

#ifndef __svr4__
#include <paths.h>
#endif

#define	_PATH_SCCSADMIN	"/usr/ccs/bin/admin"
#define	_PATH_SCCSBDIFF	"/usr/ccs/bin/bdiff"
#define	_PATH_SCCSCOMB	"/usr/ccs/bin/comb"
#define	_PATH_SCCSDELTA	"/usr/ccs/bin/delta"
#define	_PATH_SCCSDIFF	"/usr/ccs/bin/sccsdiff"
#define	_PATH_SCCSGET	"/usr/ccs/bin/get"
#define	_PATH_SCCSHELP	"/usr/ccs/bin/help"
#define	_PATH_SCCSPRS	"/usr/ccs/bin/prs"
#define	_PATH_SCCSPRT	"/usr/ccs/bin/prt"
#define	_PATH_SCCSRMDEL	"/usr/ccs/bin/rmdel"
#define	_PATH_SCCSVAL	"/usr/ccs/bin/val"
#define	_PATH_SCCSWHAT	"/usr/ccs/bin/what"
#undef _PATH_TMP
#define	_PATH_TMP	"/tmp/sccsXXXXX"
