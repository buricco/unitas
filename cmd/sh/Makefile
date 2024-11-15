CC ?= cc

sh:	main.o args.o blok.o cmd.o defs.o error.o fault.o getopt.o gmatch.o   \
	hash.o hashserv.o io.o msg.o name.o print.o service.o stak.o string.o \
	word.o xec.o ctype.o echo.o expand.o func.o macro.o pwd.o setbrk.o    \
	strsig.o test.o jobs.o bltin.o ulimit.o umask.o
	$(CC) $(LDFLAGS) -o sh main.o args.o blok.o cmd.o defs.o error.o      \
		fault.o getopt.o gmatch.o hash.o hashserv.o io.o msg.o name.o \
		print.o service.o stak.o string.o word.o xec.o ctype.o echo.o \
		expand.o func.o macro.o pwd.o setbrk.o strsig.o test.o jobs.o \
		bltin.o ulimit.o umask.o

main.o:	main.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h dup.h sym.h timeout.h
	$(CC) $(CFLAGS) -fno-builtin -c -o main.o main.c

args.o:	args.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o args.o args.c

blok.o:	blok.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o blok.o blok.c

cmd.o:	cmd.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h sym.h
	$(CC) $(CFLAGS) -fno-builtin -c -o cmd.o cmd.c

defs.o:	defs.c mode.h name.h
	$(CC) $(CFLAGS) -fno-builtin -c -o defs.o defs.c

error.o:	error.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o error.o error.c

fault.o:	fault.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o fault.o fault.c

getopt.o:	getopt.c
	$(CC) $(CFLAGS) -fno-builtin -c -o getopt.o getopt.c

gmatch.o:	gmatch.c mbtowi.h
	$(CC) $(CFLAGS) -fno-builtin -c -o gmatch.o gmatch.c

hash.o:	hash.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hash.o hash.c

hashserv.o:	hashserv.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hashserv.o hashserv.c

io.o:	io.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h dup.h
	$(CC) $(CFLAGS) -fno-builtin -c -o io.o io.c

msg.o:	msg.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h sym.h
	$(CC) $(CFLAGS) -fno-builtin -c -o msg.o msg.c

name.o:	name.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o name.o name.c

print.o:	print.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o print.o print.c

service.o:	service.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o service.o service.c

stak.o:	stak.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o stak.o stak.c

string.o:	string.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o string.o string.c

word.o:	word.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h sym.h
	$(CC) $(CFLAGS) -fno-builtin -c -o word.o word.c

xec.o:	xec.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h hash.h sym.h
	$(CC) $(CFLAGS) -fno-builtin -c -o xec.o xec.c

ctype.o:	ctype.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o ctype.o ctype.c

echo.o:	echo.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o echo.o echo.c

expand.o:	expand.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o expand.o expand.c

func.o:	func.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o func.o func.c

macro.o:	macro.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h sym.h
	$(CC) $(CFLAGS) -fno-builtin -c -o macro.o macro.c

pwd.o:	pwd.c mac.h
	$(CC) $(CFLAGS) -fno-builtin -c -o pwd.o pwd.c

setbrk.o:	setbrk.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o setbrk.o setbrk.c

strsig.o:	strsig.c
	$(CC) $(CFLAGS) -fno-builtin -c -o strsig.o strsig.c

test.o:	test.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o test.o test.c

jobs.o:	jobs.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o jobs.o jobs.c

bltin.o:	bltin.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o bltin.o bltin.c

ulimit.o:	ulimit.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o ulimit.o ulimit.c

umask.o:	umask.c defs.h mac.h mode.h name.h stak.h brkincr.h ctype.h
	$(CC) $(CFLAGS) -fno-builtin -c -o umask.o umask.c

clean:
	rm -f sh main.o args.o blok.o cmd.o defs.o error.o fault.o getopt.o   \
		gmatch.o hash.o hashserv.o io.o msg.o name.o print.o          \
		service.o stak.o string.o word.o xec.o ctype.o echo.o         \
		expand.o func.o macro.o pwd.o setbrk.o strsig.o test.o jobs.o \
		bltin.o ulimit.o umask.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin sh
	ln -fs ../../sbin/sh $(ROOT)/usr/bin/sh
	ln -fs ../../sbin/sh $(ROOT)/usr/sbin/sh
