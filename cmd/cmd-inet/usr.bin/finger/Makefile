finger:	finger.o lprint.o net.o sprint.o util.o
	$(CC) $(LDFLAGS) -c -o finger finger.o lprint.o net.o sprint.o util.o -lucb -lsocket -lnsl

finger.o:	finger.c finger.h
	$(CC) $(CFLAGS) -c -o finger.o finger.c

lprint.o:	lprint.c finger.h
	$(CC) $(CFLAGS) -c -o lprint.o lprint.c

net.o:	net.c
	$(CC) $(CFLAGS) -c -o net.o net.c


sprint.o:	sprint.c finger.h
	$(CC) $(CFLAGS) -c -o sprint.o sprint.c

util.o:	util.c finger.h
	$(CC) $(CFLAGS) -c -o util.o util.c

clean:
	rm -f finger finger.o lprint.o net.o sprint.o util.o

install:
	sh ../../../install/sysinstall.sh $(ROOT)/usr/bin finger
