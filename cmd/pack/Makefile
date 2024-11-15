CC ?= cc

pack:	pack.o
	$(CC) $(LDFLAGS) -o pack pack.o

pack.o:	pack.c
	$(CC) $(CFLAGS) -c -o pack.o pack.c

clean:
	rm -f pack pack.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin pack
