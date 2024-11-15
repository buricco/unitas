CC ?= cc
AR ?= ar

a.a:	copyn.o devtolin.o expand.o lintodev.o namtouid.o pnpsplit.o \
	substr.o tmless.o tmsecs.o uidtonam.o
	$(AR) rv a.a copyn.o devtolin.o expand.o lintodev.o namtouid.o \
		pnpsplit.o substr.o tmless.o tmsecs.o uidtonam.o

pnpsplit.o:	pnpsplit.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o pnpsplit.o pnpsplit.c

copyn.o:	copyn.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o copyn.o copyn.c

devtolin.o:	devtolin.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o devtolin.o devtolin.c

expand.o:	expand.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o expand.o expand.c

lintodev.o:	lintodev.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o lintodev.o lintodev.c

namtouid.o:	namtouid.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o namtouid.o namtouid.c

tmless.o:	tmless.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o tmless.o tmless.c

tmsecs.o:	tmsecs.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o tmsecs.o tmsecs.c

uidtonam.o:	uidtonam.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o uidtonam.o uidtonam.c

substr.o:	substr.c
	$(CC) -D_LTYPES $(CFLAGS) -I.. -c -o substr.o substr.c

clean:
	rm -f a.a copyn.o devtolin.o expand.o lintodev.o namtouid.o \
		pnpsplit.o substr.o tmless.o tmsecs.o uidtonam.o
