all:	mesg

mesg:	mesg.o
	$(CC) $(LDFLAGS) -o mesg mesg.o -lgen

mesg.o:	mesg.c
	$(CC) $(CFLAGS) -c -o mesg.o mesg.c

clean:
	rm -f mesg mesg.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin mesg
