CC ?= cc
HOSTCC ?= $(CC)

all:	spellprog hashcheck spellhist hashmake spellin spell compress

spell:	spell.sh
	cp spell.sh spell

compress:	compress.sh
	cp compress.sh compress

spellhist:
	touch spellhist

spellprog:	spellprog.o hash.o hashlook.o huff.o
	$(CC) $(LDFLAGS) -o spellprog spellprog.o hash.o hashlook.o huff.o

hashcheck:	hashcheck.o hash.o huff.o
	$(CC) $(LDFLAGS) -o hashcheck hashcheck.o hash.o huff.o

hashmake:	hashmake.o hash.o
	$(CC) $(LDFLAGS) -o hashmake hashmake.o hash.o

spellin:	spellin.o huff.o
	$(CC) $(LDFLAGS) -o spellin spellin.o huff.o

hashmake.o:	hashmake.c hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hashmake.o hashmake.c

spellin.o:	spellin.c hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o spellin.o spellin.c

spellprog.o:	spellprog.c
	$(CC) $(CFLAGS) -fno-builtin -c -o spellprog.o spellprog.c

hash.o:	hash.c hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hash.o hash.c

hashcheck.o:	hashcheck.c hash.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hashcheck.o hashcheck.c

hashlook.o:	hashlook.c hash.h huff.h
	$(CC) $(CFLAGS) -fno-builtin -c -o hashlook.o hashlook.c

huff.o:	huff.c huff.h
	$(CC) $(CFLAGS) -fno-builtin -c -o huff.o huff.c

hashmk1:	hashmk1.o
	$(HOSTCC) -o hashmk1 hashmk1.o

hashmk1.o:	hashmk1.c
	$(HOSTCC) -c -o hashmk1.o hashmk1

spellin1:	spellin1.o
	$(HOSTCC) -o spellin1 spellin1.o

spellin1.o:	spellin1.c
	$(HOSTCC) -c -o spellin1.o spellin1.c

hlista:	american list local extra hashmk1 spllin1
	cat list local extra | ./hashmk1 > htemp1
	./hashmk1 < american | sort -u - htemp1 > htemp2
	./spellin1 `wc htemp2 | sed -n 's/\([^ ]\) .*/\1/p'` < htemp2 > hlista
	rm -f htemp1 htemp2

hlistb:	british list local extra hashmk1 spllin1
	cat list local extra | ./hashmk1 > htemp1
	./hashmk1 < british | sort -u - htemp1 > htemp2
	./spellin1 `wc htemp2 | sed -n 's/\([^ ]\) .*/\1/p'` < htemp2 > hlistb
	rm -f htemp1 htemp2

hstop:	stop list local extra hashmk1 spllin1
	./hashmk1 < stop | sort -u - > htemp2
	./spellin1 `wc htemp2 | sed -n 's/\([^ ]\) .*/\1/p'` < htemp2 > hstop
	rm -f htemp1 htemp2

clean:
	rm -f spellprog hashcheck spellprog.o hash.o hashcheck.o hashlook.o huff.o spellhist hashmk1 spellin1 hashmk1.o spellin1.o hlista hlistb hstop spell hashmake spellin spellin.o hashmake.o compress
