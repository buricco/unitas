CC ?= cc
AR ?= ar

../mpwlib.a:	abspath.o any.o cat.o dname.o fatal.o fdfopen.o fmalloc.o imatch.o index.o lockit.o patoi.o repl.o satoi.o setsig.o sname.o strend.o trnslat.o userexit.o xcreat.o xlink.o xopen.o xpipe.o xunlink.o xmsg.o zero.o
	$(AR) rv ../mpwlib.a abspath.o any.o cat.o dname.o fatal.o fdfopen.o fmalloc.o imatch.o index.o lockit.o patoi.o repl.o satoi.o setsig.o sname.o strend.o trnslat.o userexit.o xcreat.o xlink.o xopen.o xpipe.o xunlink.o xmsg.o zero.o

abspath.o:	abspath.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o abspath.o abspath.c

any.o:	any.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o any.o any.c

cat.o:	cat.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o cat.o cat.c

dname.o:	dname.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o dname.o dname.c

fatal.o:	fatal.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o fatal.o fatal.c

fdfopen.o:	fdfopen.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o fdfopen.o fdfopen.c

fmalloc.o:	fmalloc.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o fmalloc.o fmalloc.c

imatch.o:	imatch.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o imatch.o imatch.c

index.o:	index.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o index.o index.c

lockit.o:	lockit.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o lockit.o lockit.c

patoi.o:	patoi.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o patoi.o patoi.c

repl.o:	repl.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o repl.o repl.c

satoi.o:	satoi.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o satoi.o satoi.c

setsig.o:	setsig.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o setsig.o setsig.c

sname.o:	sname.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o sname.o sname.c

strend.o:	strend.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o strend.o strend.c

trnslat.o:	trnslat.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o trnslat.o trnslat.c

userexit.o:	userexit.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o userexit.o userexit.c

xcreat.o:	xcreat.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xcreat.o xcreat.c

xlink.o:	xlink.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xlink.o xlink.c

xopen.o:	xopen.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xopen.o xopen.c

xpipe.o:	xpipe.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xpipe.o xpipe.c

xunlink.o:	xunlink.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xunlink.o xunlink.c

xmsg.o:	xmsg.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o xmsg.o xmsg.c

zero.o:	zero.c
	$(CC) $(CFLAGS) -I../../../sgs/inc/common -I../../hdr -c -o zero.o zero.c

clean:
	rm -f ../mpwlib.a abspath.o any.o cat.o dname.o fatal.o fdfopen.o fmalloc.o imatch.o index.o lockit.o patoi.o repl.o satoi.o setsig.o sname.o strend.o trnslat.o userexit.o xcreat.o xlink.o xopen.o xpipe.o xunlink.o xmsg.o zero.o
