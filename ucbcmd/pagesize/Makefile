CC ?= cc

pagesize:	pagesize.o
	$(CC) $(LDFLAGS) -o pagesize pagesize.o -lucb

pagesize.o:	pagesize.c
	$(CC) $(CFLAGS) -c -o pagesize.o pagesize.c

clean:
	rm -f pagesize pagesize.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb pagesize
