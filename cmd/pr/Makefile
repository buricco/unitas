CC ?= cc

pr:	pr.o egetopt.o
	$(CC) $(LDFLAGS) -o pr pr.o egetopt.o

egetopt.o:	egetopt.c extern.h
	$(CC) $(CFLAGS) -c -o egetopt.o egetopt.c

pr.o:	pr.c pr.h extern.h
	$(CC) $(CFLAGS) -c -o pr.o pr.c

clean:
	rm -f pr egetopt.o pr.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin pr
