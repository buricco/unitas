all:	mkdir

mkdir:	mkdir.o
	$(CC) $(LDFLAGS) -o mkdir mkdir.o -lgen

mkdir.o:	mkdir.c
	$(CC) $(CFLAGS) -c -o mkdir.o mkdir.c

clean:
	rm -f mkdir mkdir.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin mkdir
