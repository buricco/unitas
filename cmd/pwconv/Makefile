CC ?= cc

pwconv:	pwconv.o
	$(CC) $(LDFLAGS) -o pwconv pwconv.o

pwconv.o:	pwconv.c
	$(CC) $(CFLAGS) -c -o pwconv.o pwconv.c

clean:
	rm -f pwconv pwconv.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin pwconv
	ln -fs ../sbin/pwconv $(ROOT)/usr/bin/pwconv
