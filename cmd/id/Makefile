all:	id

id:	id.o
	$(CC) $(LDFLAGS) -o id id.o -lgen

id.o:	id.c
	$(CC) $(CFLAGS) -c -o id.o id.c

clean:
	rm -f id id.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin id
