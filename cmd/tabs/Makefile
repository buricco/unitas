CC ?= cc

tabs:	tabs.o
	$(CC) $(LDFLAGS) -o tabs tabs.o -lcurses

tabs.o:	tabs.c
	$(CC) $(CFLAGS) -c -o tabs.o tabs.c

clean:
	rm -f tabs tabs.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin tabs
