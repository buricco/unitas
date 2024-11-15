CC ?= cc

head:	head.o
	$(CC) $(LDFLAGS) -o head head.o

head.o:	head.c
	$(CC) $(CFLAGS) -c -o head.o head.c

clean:
	rm -f head head.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin head
