all:	strace strerr strclean

strace:	strace.o
	$(CC) $(LDFLAGS) -o strace strace.o

strerr:	strerr.o
	$(CC) $(LDFLAGS) -o strerr strerr.o

strclean:	strclean.o
	$(CC) $(LDFLAGS) -o strclean strclean.o

strace.o:	strace.c
	$(CC) $(CFLAGS) -Di386 -c -o strace.o strace.c

strerr.o:	strerr.c
	$(CC) $(CFLAGS) -Di386 -c -o strerr.o strerr.c

strclean.o:	strclean.c
	$(CC) $(CFLAGS) -Di386 -c -o strclean.o strclean.c

clean:
	rm -f strace strerr strclean strace.o strerr.o strclean.o

install:
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin strace
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin strclean
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin strerror
	ln -fs ../sbin/strace $(ROOT)/usr/bin/strace
	ln -fs ../sbin/strclean $(ROOT)/usr/bin/strclean
	ln -fs ../sbin/strerror $(ROOT)/usr/bin/strerror
