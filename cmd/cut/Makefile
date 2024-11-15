CC ?= cc

cut:	cut.o
	$(CC) $(LDFLAGS) -o cut cut.o

cut.o:	cut.c
	$(CC) $(CFLAGS) -c -o cut.o cut.c

clean:
	rm -f cut cut.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cut
