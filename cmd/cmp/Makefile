CC ?= cc

cmp:	cmp.o
	$(CC) $(LDFLAGS) -o cmp cmp.o

cmp.o:	cmp.c
	$(CC) $(CFLAGS) -c -o cmp.o cmp.c

clean:
	rm -f cmp cmp.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cmp
