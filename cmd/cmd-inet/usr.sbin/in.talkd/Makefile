all:	in.talkd

in.talkd:	announce.o print.o process.o table.o talkd.o
	$(CC) $(LDFLAGS) -o in.talkd announce.o print.o process.o table.o talkd.o -lsocket -lnsl

announce.o:	announce.c ctl.h
	$(CC) $(CFLAGS) -fno-builtin -c -o announce.o announce.c

print.o:	print.c ctl.h
	$(CC) $(CFLAGS) -fno-builtin -c -o print.o print.c

process.o:	process.c ctl.h
	$(CC) $(CFLAGS) -fno-builtin -c -o process.o process.c

table.o:	table.c ctl.h
	$(CC) $(CFLAGS) -fno-builtin -c -o table.o table.c

talkd.o:	talkd.c ctl.h
	$(CC) $(CFLAGS) -fno-builtin -c -o talkd.o talkd.c

clean:
	rm -f in.talkd announce.o print.o process.o table.o talkd.o
