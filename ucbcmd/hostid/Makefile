CC ?= cc

hostid:	hostid.o
	$(CC) $(LDFLAGS) -o hostid hostid.o -lucb

hostid.o:	hostid.c
	$(CC) $(CFLAGS) -c -o hostid.o hostid.c

clean:
	rm -f hostid hostid.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb hostid
