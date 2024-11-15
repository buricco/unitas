CC ?= cc

ln:	ln.o
	$(CC) $(LDFLAGS) -o ln ln.o

ln.o:	ln.c
	$(CC) $(CFLAGS) -c -o ln.o ln.c

clean:
	rm -f ln ln.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb ln
