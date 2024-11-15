all:	tcopy

tcopy:	tcopy.o err.o
	$(CC) $(LDFLAGS) -o tcopy tcopy.o err.o

err.o:	err.c err.h
	$(CC) $(CFLAGS) -c -o err.o err.c

tcopy.o:	tcopy.c err.h pathnames.h
	$(CC) $(CFLAGS) -c -o tcopy.o tcopy.c

clean:
	rm -f tcopy tcopy.o err.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb tcopy
