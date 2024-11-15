CC ?= cc

xstr:	xstr.o err.o
	$(CC) $(LDFLAGS) -o xstr xstr.o err.o

xstr.o:	xstr.c pathnames.h
	$(CC) $(CFLAGS) -c -o xstr.o xstr.c

err.o:	err.c
	$(CC) $(CFLAGS) -c -o err.o err.c

clean:
	rm -f xstr xstr.o err.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb xstr
