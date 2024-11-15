CC ?= cc

all:	dc

dc:	dc.o
	$(CC) $(LDFLAGS) -o dc dc.o

dc.o:	dc.c dc.h
	$(CC) $(CFLAGS) -c -o dc.o dc.c

clean:
	rm -f dc dc.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin dc
