CC ?= cc

units:	units.o
	$(CC) $(LDFLAGS) -o units units.o

units.o:	units.c
	$(CC) $(CFLAGS) -c -o units.o units.c

clean:
	rm -f units units.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin units
	sh ../install/sysinstall.sh $(ROOT)/usr/share/lib unittab
