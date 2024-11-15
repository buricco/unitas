CC ?= cc

fold:	fold.o
	$(CC) $(LDFLAGS) -o fold fold.o

fold.o:	fold.c
	$(CC) $(CFLAGS) -c -o fold.o fold.c

clean:
	rm -f fold fold.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin fold
