CC ?= cc

sed:	sed0.o sed1.o
	$(CC) $(LDFLAGS) -o sed sed0.o sed1.o

sed0.o:	sed0.c sed.h
	$(CC) $(CFLAGS) -c -o sed0.o sed0.c

sed1.o:	sed1.c sed.h
	$(CC) $(CFLAGS) -c -o sed1.o sed1.c

clean:
	rm -f sed sed0.o sed1.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin sed
