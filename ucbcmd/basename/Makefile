CC ?= cc

basename:	basename.o
	$(CC) $(LDFLAGS) -o basename basename.o

basename.o:	basename.c
	$(CC) $(CFLAGS) -c -o basename.o basename.c

clean:
	rm -f basename basename.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb basename
