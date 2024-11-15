CC ?= cc

all:	nl nl8

nl:	nl.o compile.o
	$(CC) $(LDFLAGS) -o nl nl.o compile.o -lgen

nl.o:	nl.c regexpr.h
	$(CC) $(CFLAGS) -c -o nl.o nl.c

nl8:	nl8.o compile.o
	$(CC) $(LDFLAGS) -o nl8 nl8.o compile.o -lgen

nl8.o:	nl.c regexpr.h
	$(CC) $(CFLAGS) -DXPG4 -c -o nl8.o nl.c

compile.o:	compile.c regexpr.h
	$(CC) $(CFLAGS) -c -o compile.o compile.c

clean:
	rm -f nl nl.o nl8 nl8.o compile.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin nl
	sh ../install/sysinstall.sh $(ROOT)/usr/bin nl
	mv $(ROOT)/usr/xpg8/bin/nl8 $(ROOT)/usr/xpg8/bin/nl
