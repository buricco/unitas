DEFRES ?= 240

../libimagen.a:	arc.o box.o charset.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o scale.o space.o
	$(AR) rc ../libimagen.a arc.o box.o charset.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o scale.o space.o

arc.o:	arc.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o arc.o arc.c

box.o:	box.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o box.o box.c

charset.o:	charset.c imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o charset.o charset.c

circle.o:	circle.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o circle.o circle.c

close.o:	close.c imp.h imPcodes.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o close.o close.c

cont.o:	cont.c imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o cont.o cont.c

dot.o:	dot.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o dot.o dot.c

erase.o:	erase.c imPcodes.h imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o erase.o erase.c

label.o:	label.c imPcodes.h imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o label.o label.c

line.o:	line.c imp.h imPcodes.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o line.o line.c

linemod.o:	linemod.c imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o linemod.o linemod.c

move.o:	move.c imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o move.o move.c

open.o:	open.c imPcodes.h imp.h
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o open.o open.c

point.o:	point.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o point.o point.c

scale.o:	scale.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o scale.o scale.c

space.o:	space.c
	$(CC) $(CFLAGS) -DDEFRES=$(DEFRES) -c -o space.o space.c

clean:
	rm -f ../libimagen.a arc.o box.o charset.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o scale.o space.o
