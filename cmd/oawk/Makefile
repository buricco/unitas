CC ?= cc
HOSTCC ?= $(CC)

oawk:	awk.lx.o b.o lib.o main.o parse.o proctab.o freeze.o run.o tran.o token.o y.tab.o
	$(CC) $(LDFLAGS) -o oawk awk.lx.o b.o lib.o main.o parse.o proctab.o freeze.o run.o tran.o token.o y.tab.o -lm

token.c: awk.h
	echo '#include "awk.h"' > token.c
	echo 'struct toke { char *tnm; int yval; } tok[] = {' >> token.c
	sed 's/#define \([^ ]*\) \(.*\)/"\1", \2,/' \
	    < awk.h >> token.c
	echo '};' >> token.c
	echo 'char *tokname(int n)' >> token.c
	echo '{' >> token.c
	echo '	if (n <= 256 || n >= LASTTOKEN)' >> token.c
	echo '		n = 257;' >> token.c
	echo '	return(tok[(n>256)?(n - 257):0].tnm);' >> token.c
	echo '}' >> token.c

awk.lx.o:	lex.yy.c awk.h
	$(CC) $(CFLAGS) -c -o awk.lx.o lex.yy.c

b.o:	b.c
	$(CC) $(CFLAGS) -c -o b.o b.c

lib.o:	lib.c
	$(CC) $(CFLAGS) -c -o lib.o lib.c

main.o:	main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

parse.o:	parse.c
	$(CC) $(CFLAGS) -c -o parse.o parse.c

proctab.o:	proctab.c
	$(CC) $(CFLAGS) -c -o proctab.o proctab.c

freeze.o:	freeze.c
	$(CC) $(CFLAGS) -c -o freeze.o freeze.c

run.o:	run.c
	$(CC) $(CFLAGS) -c -o run.o run.c

tran.o:	tran.c
	$(CC) $(CFLAGS) -c -o tran.o tran.c

token.o:	token.c
	$(CC) $(CFLAGS) -c -o token.o token.c

token0.o:	token.c
	$(HOSTCC) -c -o token0.o token.c

y.tab.o:	y.tab.c
	$(CC) $(CFLAGS) -c -o y.tab.o y.tab.c

y.tab.c:	awk.g.y
	yacc -d awk.g.y

lex.yy.c:	awk.lx.l
	lex awk.lx.l

awk.h: y.tab.c
	cp y.tab.h awk.h

proctab.c: proc
	./proc > proctab.c

proc: token0.o proc.o
	${HOSTCC} -o proc proc.o token0.o

proc.o:	proc.c
	$(HOSTCC) -c -o proc.o proc.c

clean:
	rm -f oawk token.c awk.g.o proctab.o proc proc.o awk.lx.o b.o lib.o main.o parse.o proctab.o freeze.o run.o tran.o token.o token0.o y.tab.o y.tab.c y.tab.h lex.yy.c awk.h

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin oawk
