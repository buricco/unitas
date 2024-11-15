CC ?= cc

sum:	sum.o
	$(CC) $(LDFLAGS) -o sum sum.o

sum.o:	sum.c
	$(CC) $(CFLAGS) -c -o sum.o sum.c

clean:
	rm -f sum sum.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb sum
