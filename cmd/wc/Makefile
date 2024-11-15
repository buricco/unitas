CC ?= cc

wc:	wc.o
	$(CC) $(LDFLAGS) -o wc wc.o

wc.o:	wc.c
	$(CC) $(CFLAGS) -c -o wc.o wc.c

clean:
	rm -f wc wc.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin wc
