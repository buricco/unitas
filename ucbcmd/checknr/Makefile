CC ?= cc

checknr:	checknr.o
	$(CC) $(LDFLAGS) -o checknr checknr.o

checknr.o:	checknr.c
	$(CC) $(CFLAGS) -c -o checknr.o checknr.c

clean:
	rm -f checknr checknr.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb checknr
