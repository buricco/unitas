CC ?= cc

renice:	renice.o
	$(CC) $(LDFLAGS) -o renice renice.o -lucb

renice.o:	renice.c
	$(CC) $(CFLAGS) -c -o renice.o renice.c

clean:
	rm -f renice renice.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb renice
