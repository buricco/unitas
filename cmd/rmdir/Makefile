all:	rmdir

rmdir:	rmdir.o
	$(CC) $(LDFLAGS) -o rmdir rmdir.o -lgen

rmdir.o:	rmdir.c
	$(CC) $(CFLAGS) -c -o rmdir.o rmdir.c

clean:
	rm -f rmdir rmdir.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin rmdir
	sh ../install/sysinstall.sh $(ROOT)/usr/bin rmdir
