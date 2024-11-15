all:	mkfifo

mkfifo:	mkfifo.o
	$(CC) $(LDFLAGS) -o mkfifo mkfifo.o -lgen

mkfifo.o:	mkfifo.c
	$(CC) $(CFLAGS) -c -o mkfifo.o mkfifo.c

clean:
	rm -f mkfifo mkfifo.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin mkfifo
