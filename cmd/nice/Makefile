CC ?= cc

nice:	nice.o
	$(CC) $(LDFLAGS) -o nice nice.o

nice.o:	nice.c
	$(CC) $(CFLAGS) -c -o nice.o nice.c

clean:
	rm -f nice nice.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin nice
