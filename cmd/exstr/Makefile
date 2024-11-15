CC ?= cc

exstr:	exstr.o
	$(CC) $(LDFLAGS) -o exstr exstr.o

exstr.o:	exstr.c
	$(CC) $(CFLAGS) -c -o exstr.o exstr.c

clean:
	rm -f exstr exstr.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin exstr
