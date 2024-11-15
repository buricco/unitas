CC ?= cc

deroff:	deroff.o
	$(CC) $(LDFLAGS) -o deroff deroff.o

deroff.o:	deroff.c
	$(CC) $(CFLAGS) -c -o deroff.o deroff.c

clean:
	rm -f deroff deroff.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb deroff
