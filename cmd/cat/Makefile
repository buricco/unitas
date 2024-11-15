CC ?= cc

cat:	cat.o
	$(CC) $(LDFLAGS) -o cat cat.o

cat.o:	cat.c
	$(CC) $(CFLAGS) -c -o cat.o cat.c

clean:
	rm -f cat cat.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cat
