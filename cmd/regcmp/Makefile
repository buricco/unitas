CC ?= cc

regcmp:	regcmp.o
	$(CC) $(LDFLAGS) -o regcmp regcmp.o -lgen

regcmp.o:	regcmp.c
	$(CC) $(CFLAGS) -c -o regcmp.o regcmp.c

clean:
	rm -f regcmp regcmp.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/ccs/bin regcmp
	ln -s ../ccs/bin/regcmp $(ROOT)/usr/bin/regcmp
