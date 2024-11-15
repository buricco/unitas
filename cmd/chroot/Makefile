all:	chroot

chroot:	chroot.o
	$(CC) $(LDFLAGS) -o chroot chroot.o

chroot.o:	chroot.c
	$(CC) $(CFLAGS) -c -o chroot.o chroot.c

clean:
	rm -f chroot chroot.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin chroot
	ln -s ../usr/sbin/chroot $(ROOT)/etc/chroot
