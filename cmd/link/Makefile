all:	link

link:	link.o
	$(CC) $(LDFLAGS) -o link link.o

link.o:	link.c
	$(CC) $(CFLAGS) -c -o link.o link.c

clean:
	rm -f link link.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin link
	ln -s ../usr/sbin/link $(ROOT)/etc/link
