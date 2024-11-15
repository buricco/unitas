all:	tty

tty:	tty.o
	$(CC) $(LDFLAGS) -o tty tty.o -lgen

tty.o:	tty.c
	$(CC) $(CFLAGS) -c -o tty.o tty.c

clean:
	rm -f tty tty.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin tty
