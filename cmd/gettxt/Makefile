CC ?= cc

gettxt:	gettxt.o
	$(CC) $(LDFLAGS) -o gettxt gettxt.o -lgen

gettxt.o:	gettxt.c
	$(CC) $(CFLAGS) -c -o gettxt.o gettxt.c

clean:
	rm -f gettxt gettxt.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin gettxt
