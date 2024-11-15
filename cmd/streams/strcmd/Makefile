all:	strchg strconf

strchg:	strchg.o
	$(CC) $(LDFLAGS) -o strchg strchg.o

strconf:	strconf.o
	$(CC) $(LDFLAGS) -o strconf strconf.o

strchg.o:	strchg.c
	$(CC) $(CFLAGS) -Di386 -c -o strchg.o strchg.c

strconf.o:	strconf.c
	$(CC) $(CFLAGS) -Di386 -c -o strconf.o strconf.c

clean:
	rm -f strchg strconf strchg.o strconf.o

install:
	sh ../../install/sysinstall.sh $(ROOT)/usr/bin strchg
	sh ../../install/sysinstall.sh $(ROOT)/usr/bin strconf
