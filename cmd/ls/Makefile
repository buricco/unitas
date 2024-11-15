CC ?= cc

ls:	ls.o
	$(CC) $(LDFLAGS) -o ls ls.o

ls.o:	ls.c
	$(CC) $(CFLAGS) -c -o ls.o ls.c

clean:
	rm -f ls ls.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ls
