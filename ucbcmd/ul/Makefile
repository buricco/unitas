CC ?= cc

ul:	ul.o
	$(CC) $(LDFLAGS) -o ul ul.o -lcurses

ul.o:	ul.c
	$(CC) $(CFLAGS) -c -o ul.o ul.c

clean:
	rm -f ul ul.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb ul
