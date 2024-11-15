CC ?= cc

sdiff:	sdiff.o
	$(CC) $(LDFLAGS) -o sdiff sdiff.o

sdiff.o:	sdiff.c
	$(CC) $(CFLAGS) -c -o sdiff.o sdiff.c

clean:
	rm -f sdiff sdiff.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin sdiff
