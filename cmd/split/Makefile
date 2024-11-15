CC ?= cc

split:	split.o
	$(CC) $(LDFLAGS) -o split split.o

split.o:	split.c
	$(CC) $(CFLAGS) -c -o split.o split.c

clean:
	rm -f split split.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin split
