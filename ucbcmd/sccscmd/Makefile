sccs:	sccs.o
	$(CC) $(LDFLAGS) -o sccs sccs.o

sccs.o:	sccs.c pathnames.h sysexits.h
	$(CC) $(CFLAGS) -c -o sccs.o sccs.c

clean:
	rm -f sccs sccs.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb sccs
