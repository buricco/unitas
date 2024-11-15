all:	fmtmsg

fmtmsg:	fmtmsg.o
	$(CC) $(LDFLAGS) -o fmtmsg fmtmsg.o

fmtmsg.o:	fmtmsg.c
	$(CC) $(CFLAGS) -c -o fmtmsg.o fmtmsg.c

clean:
	rm -f fmtmsg fmtmsg.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin fmtmsg
