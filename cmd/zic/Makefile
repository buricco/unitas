CC ?= cc

zic:	zic.o scheck.o ialloc.o
	$(CC) $(LDFLAGS) -o zic zic.o scheck.o ialloc.o

zic.o:	zic.c
	$(CC) $(CFLAGS) -DNOSOLAR -c -o zic.o zic.c

scheck.o:	scheck.c
	$(CC) $(CFLAGS) -DNOSOLAR -c -o scheck.o scheck.c

ialloc.o:	ialloc.c
	$(CC) $(CFLAGS) -DNOSOLAR -c -o ialloc.o ialloc.c

clean:
	rm -f zic zic.o scheck.o ialloc.o
