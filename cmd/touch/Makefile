all:	touch

touch:	touch.o
	$(CC) $(LDFLAGS) -o touch touch.o -lgen

touch.o:	touch.c
	$(CC) $(CFLAGS) -c -o touch.o touch.c

clean:
	rm -f touch touch.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin touch
