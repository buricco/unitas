CC ?= cc

pwck:	pwck.o
	$(CC) $(LDFLAGS) -o pwck pwck.o

pwck.o:	pwck.c
	$(CC) $(CFLAGS) -c -o pwck.o pwck.c

clean:
	rm -f pwck pwck.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin pwck
	ln -s ../usr/sbin/pwck $(ROOT)/etc/pwck
