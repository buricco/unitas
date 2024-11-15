CC ?= cc

test:	test.o
	$(CC) $(LDFLAGS) -o test test.o

test.o:	test.c
	$(CC) $(CFLAGS) -fno-builtin -c -o test.o test.c

clean:
	rm -f test test.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb test
