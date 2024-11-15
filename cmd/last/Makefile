CC ?= cc

last:	last.o
	$(CC) $(LDFLAGS) -o last last.o

last.o:	last.c
	$(CC) $(CFLAGS) -c -o last.o last.c

clean:
	rm -f last last.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin last
