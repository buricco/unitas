CC ?= cc

autopush:	autopush.o
	$(CC) $(LDFLAGS) -o autopush autopush.o

autopush.o:	autopush.c
	$(CC) $(CFLAGS) -c -o autopush.o autopush.c

clean:
	rm -f autopush autopush.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin autopush
	ln -fs ../sbin/autopush $(ROOT)/etc/autopush
	ln -fs ../../sbin/autopush $(ROOT)/usr/sbin/autopush
