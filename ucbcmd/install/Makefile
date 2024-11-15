CC ?= cc

_install:	install.o
	$(CC) $(LDFLAGS) -o _install install.o

install.o:	install.c
	$(CC) $(CFLAGS) -c -o install.o install.c

clean:
	rm -f _install install.o

install:
	cp _install $(BOOT)/usr/ucb/install
