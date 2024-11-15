CC ?= cc
AR ?= ar

../cassi.a:	cmrcheck.o deltack.o error.o filehand.o gf.o
	$(AR) rv ../cassi.a cmrcheck.o deltack.o error.o filehand.o gf.o

cmrcheck.o:	cmrcheck.c
	$(CC) $(CFLAGS) -I../../hdr -c -o cmrcheck.o cmrcheck.c

deltack.o:	deltack.c
	$(CC) $(CFLAGS) -I../../hdr -c -o deltack.o deltack.c

error.o:	error.c
	$(CC) $(CFLAGS) -I../../hdr -c -o error.o error.c

filehand.o:	filehand.c
	$(CC) $(CFLAGS) -I../../hdr -c -o filehand.o filehand.c

gf.o:	gf.c
	$(CC) $(CFLAGS) -I../../hdr -c -o gf.o gf.c

clean:
	rm -f ../cassi.a cmrcheck.o deltack.o error.o filehand.o gf.o
