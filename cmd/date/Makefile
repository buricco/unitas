all:	date

date:	date.o
	$(CC) $(LDFLAGS) -o date date.o -lgen

date.o:	date.c
	$(CC) $(CFLAGS) -c -o date.o date.c

clean:
	rm -f date date.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin date
