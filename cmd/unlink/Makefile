all:	unlink

unlink:	unlink.o
	$(CC) $(LDFLAGS) -o unlink unlink.o

unlink.o:	unlink.c
	$(CC) $(CFLAGS) -c -o unlink.o unlink.c

clean:
	rm -f unlink unlink.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin unlink
	ln -s ../usr/sbin/unlink $(ROOT)/etc/unlink
