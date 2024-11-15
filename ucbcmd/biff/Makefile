CC ?= cc

biff:	biff.o
	$(CC) $(LDFLAGS) -o biff biff.o

biff.o:	biff.c
	$(CC) $(CFLAGS) -c -o biff.o biff.c

clean:
	rm -f biff biff.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb biff
