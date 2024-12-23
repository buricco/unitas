/*-
 * Copyright (c) 1991 The Regents of the University of California.
 * All rights reserved.
 *
 * This module is believed to contain source code proprietary to AT&T.
 * Use and redistribution is subject to the Berkeley Software License
 * Agreement and your Software Agreement with AT&T (Western Electric).
 */

#ifndef lint
char copyright[] =
    "@(#) Copyright (c) 1991 The Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)proc.c	4.4 (Berkeley) 4/17/91";
#endif /* not lint */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "awk.h"
#ifndef NULL
#define NULL 0
#endif
extern char *tokname(int);
struct xx {
  int token;
  char *name;
  char *pname;
} proc[] = {
    {PROGRAM, "program", NULL},
    {BOR, "boolop", " || "},
    {AND, "boolop", " && "},
    {NOT, "boolop", " !"},
    {NE, "relop", " != "},
    {EQ, "relop", " == "},
    {LE, "relop", " <= "},
    {LT, "relop", " < "},
    {GE, "relop", " >= "},
    {GT, "relop", " > "},
    {ARRAY, "array", NULL},
    {INDIRECT, "indirect", "$("},
    {SUBSTR, "substr", "substr"},
    {INDEX, "sindex", "sindex"},
    {SPRINTF, "xsprintf", "sprintf "},
    {ADD, "arith", " + "},
    {MINUS, "arith", " - "},
    {MULT, "arith", " * "},
    {DIVIDE, "arith", " / "},
    {MOD, "arith", " % "},
    {UMINUS, "arith", " -"},
    {PREINCR, "incrdecr", "++"},
    {POSTINCR, "incrdecr", "++"},
    {PREDECR, "incrdecr", "--"},
    {POSTDECR, "incrdecr", "--"},
    {CAT, "cat", " "},
    {PASTAT, "pastat", NULL},
    {PASTAT2, "dopa2", NULL},
    {MATCH, "matchop", " ~ "},
    {NOTMATCH, "matchop", " !~ "},
    {PRINTF, "aprintf", "printf"},
    {PRINT, "print", "print"},
    {SPLIT, "split", "split"},
    {ASSIGN, "assign", " = "},
    {ADDEQ, "assign", " += "},
    {SUBEQ, "assign", " -= "},
    {MULTEQ, "assign", " *= "},
    {DIVEQ, "assign", " /= "},
    {MODEQ, "assign", " %= "},
    {IF, "ifstat", "if("},
    {WHILE, "whilestat", "while("},
    {FOR, "forstat", "for("},
    {IN, "instat", "instat"},
    {NEXT, "jump", "next"},
    {EXIT, "jump", "exit"},
    {BREAK, "jump", "break"},
    {CONTINUE, "jump", "continue"},
    {FNCN, "fncn", "fncn"},
    {GETLINE, "getline", "getline"},
    {0, ""},
};
#define SIZE LASTTOKEN - FIRSTTOKEN
char *table[SIZE];
char *names[SIZE];

int main(int unused1, char **unused2) 
{
  struct xx *p;
  int i;

  printf("#include \"awk.def\"\n");
  printf("#define getline getlin /* workaround for newer libc */\n");
  printf("obj nullproc();\n");
  for (p = proc; p->token; p++)
  {
    /* 
     * uso: Have to do this twice because kek, might get a segvee from a
     *      braindead C compiler
     */
    if (p == proc)
      printf("extern obj %s();\n", p->name);
    else
    {
      if (strcmp(p->name, (p - 1)->name))
        printf("extern obj %s();\n", p->name);
    }
  }
  for (p = proc; p->token != 0; p++)
    table[p->token - FIRSTTOKEN] = p->name;
  printf("obj (*proctab[%d])() = {\n", SIZE);
  for (i = 0; i < SIZE; i++)
    if (table[i] == 0)
      printf("/*%s*/\tnullproc,\n", tokname(i + FIRSTTOKEN));
    else
      printf("/*%s*/\t%s,\n", tokname(i + FIRSTTOKEN), table[i]);
  printf("};\n");
  printf("char *printname[%d] = {\n", SIZE);
  for (p = proc; p->token != 0; p++)
    names[p->token - FIRSTTOKEN] = p->pname;
  for (i = 0; i < SIZE; i++)
    printf("/*%s*/\t\"%s\",\n", tokname(i + FIRSTTOKEN),
           names[i] ? names[i] : "");
  printf("};\n");
  exit(0);
}
