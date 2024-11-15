all:	mknod

mknod:	mknod.o
	$(CC) $(LDFLAGS) -o mknod mknod.o -lgen

mknod.o:	mknod.c
	$(CC) $(CFLAGS) -c -o mknod.o mknod.c

clean:
	rm -f mknod mknod.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin mknod
	ln -fs ../sbin/mknod $(ROOT)/etc/mknod
	ln -fs ../../sbin/mknod $(ROOT)/usr/sbin/mknod
