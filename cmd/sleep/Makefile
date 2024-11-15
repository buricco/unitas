all:	sleep

sleep:	sleep.o
	$(CC) $(LDFLAGS) -o sleep sleep.o -lgen

sleep.o:	sleep.c
	$(CC) $(CFLAGS) -c -o sleep.o sleep.c

clean:
	rm -f sleep sleep.o

install:
	sh ../install/sysinstall.sh $(ROOT)/sbin sleep
	ln -fs ../../sbin/sleep $(ROOT)/usr/bin/sleep
	ln -fs ../../sbin/sleep $(ROOT)/usr/sbin/sleep
