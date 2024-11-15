CC ?= cc

halt:	halt.o
	$(CC) $(LDFLAGS) -o halt halt.o -lucb

halt.o:	halt.c
	$(CC) $(CFLAGS) -c -o halt.o halt.c

clean:
	rm -f halt halt.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb halt
