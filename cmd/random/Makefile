all:	random

random:	random.o
	$(CC) $(LDFLAGS) -o random random.o

random.o:	random.c
	$(CC) $(CFLAGS) -c -o random.o random.c

clean:
	rm -f random random.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin random
