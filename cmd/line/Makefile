CC ?= cc

line:	line.o
	$(CC) $(LDFLAGS) -o line line.o

line.o:	line.c
	$(CC) $(CFLAGS) -c -o line.o line.c

clean:
	rm -f line line.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin line
