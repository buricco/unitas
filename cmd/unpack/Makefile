CC ?= cc

unpack:	unpack.o
	$(CC) $(LDFLAGS) -o unpack unpack.o

unpack.o:	unpack.c
	$(CC) $(CFLAGS) -c -o unpack.o unpack.c

clean:
	rm -f unpack unpack.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin unpack
