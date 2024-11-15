CC ?= cc

printf:	printf.o
	$(CC) $(LDFLAGS) -o printf printf.o

printf.o:	printf.c
	$(CC) $(CFLAGS) -c -o printf.o printf.c

clean:
	rm -f printf printf.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin printf
