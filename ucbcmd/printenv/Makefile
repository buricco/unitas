CC ?= cc

printenv:	printenv.o
	$(CC) $(LDFLAGS) -o printenv printenv.o

printenv.o:	printenv.c
	$(CC) $(CFLAGS) -c -o printenv.o printenv.c

clean:
	rm -f printenv printenv.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb printenv
