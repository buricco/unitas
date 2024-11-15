CC ?= cc

groups:	groups.o
	$(CC) $(LDFLAGS) -o groups groups.o

groups.o:	groups.c
	$(CC) $(CFLAGS) -c -o groups.o groups.c

clean:
	rm -f groups groups.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb groups
