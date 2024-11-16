../libdumb.a:	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o
	$(AR) rc ../libdumb.a arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o

arc.o:	arc.c dumb.h
	$(CC) $(CFLAGS) -c -o arc.o arc.c

box.o:	box.c
	$(CC) $(CFLAGS) -c -o box.o box.c

circle.o:	circle.c
	$(CC) $(CFLAGS) -c -o circle.o circle.c

close.o:	close.c dumb.h
	$(CC) $(CFLAGS) -c -o close.o close.c

cont.o:	cont.c dumb.h
	$(CC) $(CFLAGS) -c -o cont.o cont.c

dot.o:	dot.c
	$(CC) $(CFLAGS) -c -o dot.o dot.c

erase.o:	erase.c dumb.h
	$(CC) $(CFLAGS) -c -o erase.o erase.c

label.o:	label.c dumb.h
	$(CC) $(CFLAGS) -c -o label.o label.c

line.o:	line.c dumb.h
	$(CC) $(CFLAGS) -c -o line.o line.c

linemod.o:	linemod.c
	$(CC) $(CFLAGS) -c -o linemod.o linemod.c

move.o:	move.c dumb.h
	$(CC) $(CFLAGS) -c -o move.o move.c

open.o:	open.c dumb.h
	$(CC) $(CFLAGS) -c -o open.o open.c

point.o:	point.c dumb.h
	$(CC) $(CFLAGS) -c -o point.o point.c

space.o:	space.c dumb.h
	$(CC) $(CFLAGS) -c -o space.o space.c

subr.o:	subr.c dumb.h
	$(CC) $(CFLAGS) -c -o subr.o subr.c

clean:
	rm -f ../libdumb.a arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o
