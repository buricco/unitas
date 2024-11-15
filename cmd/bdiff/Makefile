CC ?= cc

bdiff:	bdiff.o
	$(CC) $(LDFLAGS) -o bdiff bdiff.o -lucb

bdiff.o:	bdiff.c fatal.h
	$(CC) $(CFLAGS) -c -o bdiff.o bdiff.c

clean:
	rm -f bdiff bdiff.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin bdiff
