CC ?= cc

srchtxt:	srchtxt.o compile.o strecpy.o
	$(CC) $(LDFLAGS) -o srchtxt srchtxt.o compile.o strecpy.o -lgen

srchtxt.o:	srchtxt.c regexpr.h
	$(CC) $(CFLAGS) -c -o srchtxt.o srchtxt.c

compile.o:	compile.c regexpr.h
	$(CC) $(CFLAGS) -c -o compile.o compile.c

strecpy.o:	strecpy.c
	$(CC) $(CFLAGS) -c -o strecpy.o strecpy.c

clean:
	rm -f srchtxt srchtxt.o compile.o strecpy.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin srchtxt
