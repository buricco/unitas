all:	cscope

cscope:	main.o dir.o crossref.o lex.yy.o lookup.o command.o display.o find.o edit.o exec.o help.o history.o input.o alloc.o basename.o compath.o y.tab.o invlib.o logdir.o mouse.o mygetenv.o mypopen.o vpaccess.o vpfopen.o vpinit.o vpopen.o
	$(CC) $(LDFLAGS) -o cscope main.o dir.o crossref.o lex.yy.o lookup.o command.o display.o find.o edit.o exec.o help.o history.o input.o alloc.o basename.o compath.o y.tab.o invlib.o logdir.o mouse.o mygetenv.o mypopen.o vpaccess.o vpfopen.o vpinit.o vpopen.o -lcurses -lgen -ll

main.o:	main.c global.h constants.h invlib.h library.h version.h
	$(CC) $(CFLAGS) -I. -c -o main.o main.c

dir.o:	dir.c global.h constants.h invlib.h library.h vp.h
	$(CC) $(CFLAGS) -I. -c -o dir.o dir.c

crossref.o:	crossref.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o crossref.o crossref.c

lex.yy.o:	lex.yy.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o lex.yy.o lex.yy.c

lookup.o:	lookup.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o lookup.o lookup.c

command.o:	command.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o command.o command.c

display.o:	display.c global.h constants.h invlib.h library.h version.h
	$(CC) $(CFLAGS) -I. -c -o display.o display.c

find.o:	find.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o find.o find.c

edit.o:	edit.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o edit.o edit.c

exec.o:	exec.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o exec.o exec.c

help.o:	help.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o help.o help.c

history.o:	history.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o history.o history.c

input.o:	input.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o input.o input.c

alloc.o:	alloc.c
	$(CC) $(CFLAGS) -I. -c -o alloc.o alloc.c

basename.o:	basename.c
	$(CC) $(CFLAGS) -I. -c -o basename.o basename.c

compath.o:	compath.c
	$(CC) $(CFLAGS) -I. -c -o compath.o compath.c

y.tab.o:	y.tab.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o y.tab.o y.tab.c

invlib.o:	invlib.c invlib.h
	$(CC) $(CFLAGS) -I. -c -o invlib.o invlib.c

logdir.o:	logdir.c
	$(CC) $(CFLAGS) -I. -c -o logdir.o logdir.c

mouse.o:	mouse.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o mouse.o mouse.c

mygetenv.o:	mygetenv.c
	$(CC) $(CFLAGS) -I. -c -o mygetenv.o mygetenv.c

mypopen.o:	mypopen.c global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o mypopen.o mypopen.c

vpaccess.o:	vpaccess.c vp.h
	$(CC) $(CFLAGS) -I. -c -o vpaccess.o vpaccess.c

vpfopen.o:	vpfopen.c vp.h global.h constants.h invlib.h library.h
	$(CC) $(CFLAGS) -I. -c -o vpfopen.o vpfopen.c

vpinit.o:	vpinit.c vp.h library.h constants.h
	$(CC) $(CFLAGS) -I. -c -o vpinit.o vpinit.c

vpopen.o:	vpopen.c vp.h
	$(CC) $(CFLAGS) -I. -c -o vpopen.o vpopen.c

lex.yy.c:	scanner.l
	lex -ln scanner.l

y.tab.c:	egrep.y
	yacc egrep.y

clean:
	rm -f cscope main.o dir.o crossref.o lex.yy.o lookup.o command.o display.o find.o edit.o exec.o help.o history.o input.o alloc.o basename.o compath.o y.tab.o invlib.o logdir.o mouse.o mygetenv.o mypopen.o vpaccess.o vpfopen.o vpinit.o vpopen.o lex.yy.c y.tab.c
