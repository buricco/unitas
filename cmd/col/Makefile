CC ?= cc

col:	col.o err.o strtonum.o
	$(CC) $(LDFLAGS) -o col col.o err.o strtonum.o

col.o:	col.c err.h strtonum.h
	$(CC) $(CFLAGS) -c -o col.o col.c

err.o:	err.c err.h
	$(CC) $(CFLAGS) -c -o err.o err.c

strtonum.o:	strtonum.c
	$(CC) $(CFLAGS) -c -o strtonum.o strtonum.c

clean:
	rm -f col col.o err.o strtonum.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin col
