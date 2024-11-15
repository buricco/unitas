cal:	cal.o
	$(CC) -o cal cal.o

cal.o:	cal.c
	$(CC) -c -o cal.o cal.c

clean:
	rm -f cal cal.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cal
