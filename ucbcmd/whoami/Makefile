CC ?= cc

whoami:	whoami.o
	$(CC) $(LDFLAGS) -o whoami whoami.o

whoami.o:	whoami.c
	$(CC) $(CFLAGS) -c -o whoami.o whoami.c

clean:
	rm -f whoami whoami.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb whoami
