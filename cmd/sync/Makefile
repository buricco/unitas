CC ?= cc

sync:	sync.o
	$(CC) $(LDFLAGS) -o sync sync.o

sync.o:	sync.c
	$(CC) $(CFLAGS) -c -o sync.o sync.c

clean:
	rm -f sync sync.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin sync
	ln -fs ../../sbin/sync $(ROOT)/usr/bin/sync
	ln -fs ../../sbin/sync $(ROOT)/usr/sbin/sync
