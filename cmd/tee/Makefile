all:	tee

tee:	tee.o
	$(CC) $(LDFLAGS) -o tee tee.o -lgen

tee.o:	tee.c
	$(CC) $(CFLAGS) -c -o tee.o tee.c

clean:
	rm -f tee tee.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin tee
