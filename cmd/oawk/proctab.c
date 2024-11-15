#include "awk.def"
#define getline getlin /* workaround for newer libc */
obj nullproc();
extern obj program();
extern obj boolop();
extern obj relop();
extern obj array();
extern obj indirect();
extern obj substr();
extern obj sindex();
extern obj xsprintf();
extern obj arith();
extern obj incrdecr();
extern obj cat();
extern obj pastat();
extern obj dopa2();
extern obj matchop();
extern obj aprintf();
extern obj print();
extern obj split();
extern obj assign();
extern obj ifstat();
extern obj whilestat();
extern obj forstat();
extern obj instat();
extern obj jump();
extern obj fncn();
extern obj getline();
obj (*proctab[76])() = {
/*FIRSTTOKEN*/	nullproc,
/*FINAL*/	nullproc,
/*FATAL*/	nullproc,
/*LT*/	relop,
/*LE*/	relop,
/*GT*/	relop,
/*GE*/	relop,
/*EQ*/	relop,
/*NE*/	relop,
/*MATCH*/	matchop,
/*NOTMATCH*/	matchop,
/*APPEND*/	nullproc,
/*ADD*/	arith,
/*MINUS*/	arith,
/*MULT*/	arith,
/*DIVIDE*/	arith,
/*MOD*/	arith,
/*UMINUS*/	arith,
/*ASSIGN*/	assign,
/*ADDEQ*/	assign,
/*SUBEQ*/	assign,
/*MULTEQ*/	assign,
/*DIVEQ*/	assign,
/*MODEQ*/	assign,
/*JUMP*/	nullproc,
/*XBEGIN*/	nullproc,
/*XEND*/	nullproc,
/*NL*/	nullproc,
/*PRINT*/	print,
/*PRINTF*/	aprintf,
/*SPRINTF*/	xsprintf,
/*SPLIT*/	split,
/*IF*/	ifstat,
/*ELSE*/	nullproc,
/*WHILE*/	whilestat,
/*FOR*/	forstat,
/*IN*/	instat,
/*NEXT*/	jump,
/*EXIT*/	jump,
/*BREAK*/	jump,
/*CONTINUE*/	jump,
/*PROGRAM*/	program,
/*PASTAT*/	pastat,
/*PASTAT2*/	dopa2,
/*ASGNOP*/	nullproc,
/*BOR*/	boolop,
/*AND*/	boolop,
/*NOT*/	boolop,
/*NUMBER*/	nullproc,
/*VAR*/	nullproc,
/*ARRAY*/	array,
/*FNCN*/	fncn,
/*SUBSTR*/	substr,
/*LSUBSTR*/	nullproc,
/*INDEX*/	sindex,
/*GETLINE*/	getline,
/*RELOP*/	nullproc,
/*MATCHOP*/	nullproc,
/*OR*/	nullproc,
/*STRING*/	nullproc,
/*DOT*/	nullproc,
/*CCL*/	nullproc,
/*NCCL*/	nullproc,
/*CHAR*/	nullproc,
/*CAT*/	cat,
/*STAR*/	nullproc,
/*PLUS*/	nullproc,
/*QUEST*/	nullproc,
/*POSTINCR*/	incrdecr,
/*PREINCR*/	incrdecr,
/*POSTDECR*/	incrdecr,
/*PREDECR*/	incrdecr,
/*INCR*/	nullproc,
/*DECR*/	nullproc,
/*FIELD*/	nullproc,
/*INDIRECT*/	indirect,
};
char *printname[76] = {
/*FIRSTTOKEN*/	"",
/*FINAL*/	"",
/*FATAL*/	"",
/*LT*/	" < ",
/*LE*/	" <= ",
/*GT*/	" > ",
/*GE*/	" >= ",
/*EQ*/	" == ",
/*NE*/	" != ",
/*MATCH*/	" ~ ",
/*NOTMATCH*/	" !~ ",
/*APPEND*/	"",
/*ADD*/	" + ",
/*MINUS*/	" - ",
/*MULT*/	" * ",
/*DIVIDE*/	" / ",
/*MOD*/	" % ",
/*UMINUS*/	" -",
/*ASSIGN*/	" = ",
/*ADDEQ*/	" += ",
/*SUBEQ*/	" -= ",
/*MULTEQ*/	" *= ",
/*DIVEQ*/	" /= ",
/*MODEQ*/	" %= ",
/*JUMP*/	"",
/*XBEGIN*/	"",
/*XEND*/	"",
/*NL*/	"",
/*PRINT*/	"print",
/*PRINTF*/	"printf",
/*SPRINTF*/	"sprintf ",
/*SPLIT*/	"split",
/*IF*/	"if(",
/*ELSE*/	"",
/*WHILE*/	"while(",
/*FOR*/	"for(",
/*IN*/	"instat",
/*NEXT*/	"next",
/*EXIT*/	"exit",
/*BREAK*/	"break",
/*CONTINUE*/	"continue",
/*PROGRAM*/	"",
/*PASTAT*/	"",
/*PASTAT2*/	"",
/*ASGNOP*/	"",
/*BOR*/	" || ",
/*AND*/	" && ",
/*NOT*/	" !",
/*NUMBER*/	"",
/*VAR*/	"",
/*ARRAY*/	"",
/*FNCN*/	"fncn",
/*SUBSTR*/	"substr",
/*LSUBSTR*/	"",
/*INDEX*/	"sindex",
/*GETLINE*/	"getline",
/*RELOP*/	"",
/*MATCHOP*/	"",
/*OR*/	"",
/*STRING*/	"",
/*DOT*/	"",
/*CCL*/	"",
/*NCCL*/	"",
/*CHAR*/	"",
/*CAT*/	" ",
/*STAR*/	"",
/*PLUS*/	"",
/*QUEST*/	"",
/*POSTINCR*/	"++",
/*PREINCR*/	"++",
/*POSTDECR*/	"--",
/*PREDECR*/	"--",
/*INCR*/	"",
/*DECR*/	"",
/*FIELD*/	"",
/*INDIRECT*/	"$(",
};
