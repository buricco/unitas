all:	nohup

nohup:	nohup.o
	$(CC) $(LDFLAGS) -o nohup nohup.o -lgen

nohup.o:	nohup.c
	$(CC) $(CFLAGS) -c -o nohup.o nohup.c

clean:
	rm -f nohup nohup.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin nohup
