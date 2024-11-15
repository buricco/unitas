CC ?= cc

look:	look.o
	$(CC) $(LDFLAGS) -o look look.o

look.o:	look.c
	$(CC) $(CFLAGS) -c -o look.o look.c

clean:
	rm -f look look.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb look
