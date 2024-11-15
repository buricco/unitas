CC ?= cc

grpck:	grpck.o
	$(CC) $(LDFLAGS) -o grpck grpck.o

grpck.o:	grpck.c
	$(CC) $(CFLAGS) -c -o grpck.o grpck.c

clean:
	rm -f grpck grpck.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin grpck
	ln -s ../usr/sbin/grpck $(ROOT)/etc/grpck
