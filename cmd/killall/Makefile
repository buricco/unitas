CC ?= cc

all:	killall

killall:	killall.o strsig.o
	$(CC) $(LDFLAGS) -o killall killall.o strsig.o

killall.o:	killall.c
	$(CC) $(CFLAGS) -c -o killall.o killall.c

strsig.o:	strsig.c
	$(CC) $(CFLAGS) -c -o strsig.o strsig.c

clean:
	rm -f killall killall.o strsig.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin killall
	ln -fs ../sbin/killall $(ROOT)/etc/killall
	ln -fs ../../sbin/killall $(ROOT)/usr/sbin/killall
