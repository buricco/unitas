all:	groups

groups:	groups.o
	$(CC) $(LDFLAGS) -o groups groups.o -lgen

groups.o:	groups.c
	$(CC) $(CFLAGS) -c -o groups.o groups.c

clean:
	rm -f groups groups.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin groups
