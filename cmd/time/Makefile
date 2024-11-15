CC ?= cc

time:	time.o
	$(CC) $(LDFLAGS) -o time time.o -lgen

time.o:	time.c
	$(CC) $(CFLAGS) -c -o time.o time.c

clean:
	rm -f time time.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin time
