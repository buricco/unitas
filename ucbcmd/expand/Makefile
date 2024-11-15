all:	expand unexpand

expand:	expand.o
	$(CC) $(LDFLAGS) -o expand expand.o

unexpand:	unexpand.o
	$(CC) $(LDFLAGS) -o unexpand unexpand.o

expand.o:	expand.c
	$(CC) $(CFLAGS) -c -o expand.o expand.c

unexpand.o:	unexpand.c
	$(CC) $(CFLAGS) -c -o unexpand.o unexpand.c

clean:
	rm -f expand unexpand expand.o unexpand.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb expand
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb unexpand
