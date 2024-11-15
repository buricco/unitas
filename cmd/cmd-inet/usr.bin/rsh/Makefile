CC ?= cc

rsh:	rsh.o err.o
	$(CC) $(LDFLAGS) -o rsh rsh.o err.o -lucb -lsocket

rsh.o:	rsh.c err.h pathnames.h
	$(CC) $(CFLAGS) -c -o rsh.o rsh.c

err.o:	err.c err.h
	$(CC) $(CFLAGS) -c -o err.o err.c

clean:
	rm -f rsh rsh.o err.o

install:
	sh ../../../install/sysinstall.sh $(ROOT)/usr/bin rsh
