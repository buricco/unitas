CC ?= cc

uname:	uname.o
	$(CC) $(LDFLAGS) -o uname uname.o

uname.o:	uname.c
	$(CC) $(CFLAGS) -c -o uname.o uname.c

clean:
	rm -f uname uname.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin uname
	sh ../install/sysinstall.sh $(ROOT)/sbin uname
	ln -fs ../sbin/uname $(ROOT)/usr/bin/uname
