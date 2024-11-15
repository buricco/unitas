all:	factor

factor:	factor.o
	$(CC) $(LDFLAGS) -o factor factor.o

factor.o:	factor.c
	$(CC) $(CFLAGS) -c -o factor.o factor.c

clean:
	rm -f factor factor.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin factor
