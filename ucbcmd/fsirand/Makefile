CC ?= cc

fsirand:	fsirand.o
	$(CC) $(LDFLAGS) -o fsirand fsirand.o

fsirand.o:	fsirand.c
	$(CC) $(CFLAGS) -c -o fsirand.o fsirand.c

clean:
	rm -f fsirand fsirand.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb fsirand
