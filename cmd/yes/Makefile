CC ?= cc

yes:	yes.o
	$(CC) $(LDFLAGS) -o yes yes.o

yes.o:	yes.c
	$(CC) $(CFLAGS) -c -o yes.o yes.c

clean:
	rm -f yes yes.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin yes
