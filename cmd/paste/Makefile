CC ?= cc

paste:	paste.o
	$(CC) $(LDFLAGS) -o paste paste.o

paste.o:	paste.c
	$(CC) $(CFLAGS) -c -o paste.o paste.c

clean:
	rm -f paste paste.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin paste
