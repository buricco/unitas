CC ?= cc

more:	more.o
	$(CC) $(LDFLAGS) -o more more.o -lcurses -lgen

more.o:	more.c
	$(CC) $(CFLAGS) -c -o more.o more.c

clean:
	rm -f more more.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin more
	sh ../install/sysinstall.sh $(ROOT)/usr/lib more.help
