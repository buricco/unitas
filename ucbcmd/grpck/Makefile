CC ?= cc

grpck:	grpck.o
	$(CC) $(LDFLAGS) -o grpck grpck.o

grpck.o:	grpck.c
	$(CC) $(CFLAGS) -c -o grpck.o grpck.c

clean:
	rm -f grpck grpck.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb grpck
