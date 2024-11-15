CC ?= cc

rm:	rm.o
	$(CC) $(LDFLAGS) -o rm rm.o

rm.o:	rm.c
	$(CC) $(CFLAGS) -c -o rm.o rm.c

clean:
	rm -f rm rm.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin rm
	sh ../install/sysinstall.sh $(ROOT)/usr/bin rm
