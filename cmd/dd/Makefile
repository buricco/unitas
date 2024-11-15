CC ?= cc

dd:	dd.o
	$(CC) $(LDFLAGS) -o dd dd.o

dd.o:	dd.c
	$(CC) $(CFLAGS) -c -o dd.o dd.c

clean:
	rm -f dd dd.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin dd
	sh ../install/sysinstall.sh $(ROOT)/sbin dd
	ln -fs ../sbin/dd $(ROOT)/usr/bin/dd
