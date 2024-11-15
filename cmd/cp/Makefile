CC ?= cc

cp:	cp.o
	$(CC) $(LDFLAGS) -o cp cp.o -lgen -lsocket -lnsl

cp.o:	cp.c
	$(CC) $(CFLAGS) -c -o cp.o cp.c

clean:
	rm -f cp cp.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin cp
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cp
	ln -sf cp $(ROOT)/sbin/mv
	ln -sf cp $(ROOT)/sbin/ln
	ln -sf cp $(ROOT)/usr/bin/mv
	ln -sf cp $(ROOT)/usr/bin/ln
