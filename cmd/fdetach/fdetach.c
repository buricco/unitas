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

/*
 * fdetach is specific to System V.
 * There is no way to get this to work on kNetBSD; the underlying interface is
 * simply not there.  Therefore, just exit with an error.
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char *copyright="@(#) (C) Copyright 2024 S. V. Nickolas\n";

int main (int argc, char **argv)
{
 int e;
 char *a0;
 
 a0=strrchr(*argv,'/');
 if (a0) a0++; else a0=*argv;

#ifdef __svr4__ 
 if (argc!=2)
 {
  fprintf (stderr, "%s: usage: %s pathname\n", a0, a0);
  return 1;
 }
 
 if (fdetach(argv[1])<0)
 {
  fprintf (stderr, "%s: %s: %s\n", a0, argv[1], strerror(errno));
  return 1;
 }
 
 return 0;
#else
 fprintf (stderr, "%s: This command is not supported.\n", a0);
 return 1;
#endif
}
