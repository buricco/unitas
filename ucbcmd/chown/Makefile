CC ?= cc

chown:	chown.o
	$(CC) $(LDFLAGS) -o chown chown.o

chown.o:	chown.c
	$(CC) $(CFLAGS) -c -o chown.o chown.c

clean:
	rm -f chown chown.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb chown
