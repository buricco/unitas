CC ?= cc

tr:	tr.o str.o
	$(CC) $(LDFLAGS) -o tr tr.o str.o

tr.o:	tr.c extern.h
	$(CC) $(CFLAGS) -c -o tr.o tr.c

str.o:	str.c extern.h
	$(CC) $(CFLAGS) -c -o str.o str.c

clean:
	rm -f tr tr.o str.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb tr
