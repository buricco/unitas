../libhp7221.a:	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o
	$(AR) rc ../libhp7221.a arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o

arc.o:	arc.c hp7221.h
	$(CC) $(CFLAGS) -c -o arc.o arc.c

box.o:	box.c
	$(CC) $(CFLAGS) -c -o box.o box.c

circle.o:	circle.c hp7221.h
	$(CC) $(CFLAGS) -c -o circle.o circle.c

close.o:	close.c hp7221.h
	$(CC) $(CFLAGS) -c -o close.o close.c

cont.o:	cont.c hp7221.h
	$(CC) $(CFLAGS) -c -o cont.o cont.c

dot.o:	dot.c
	$(CC) $(CFLAGS) -c -o dot.o dot.c

erase.o:	erase.c
	$(CC) $(CFLAGS) -c -o erase.o erase.c

label.o:	label.c hp7221.h
	$(CC) $(CFLAGS) -c -o label.o label.c

line.o:	line.c hp7221.h
	$(CC) $(CFLAGS) -c -o line.o line.c

linemod.o:	linemod.c hp7221.h
	$(CC) $(CFLAGS) -c -o linemod.o linemod.c

move.o:	move.c hp7221.h
	$(CC) $(CFLAGS) -c -o move.o move.c

open.o:	open.c hp7221.h
	$(CC) $(CFLAGS) -c -o open.o open.c

point.o:	point.c hp7221.h
	$(CC) $(CFLAGS) -c -o point.o point.c

space.o:	space.c hp7221.h
	$(CC) $(CFLAGS) -c -o space.o space.c

subr.o:	subr.c hp7221.h
	$(CC) $(CFLAGS) -c -o subr.o subr.c

clean:
	rm -f ../libhp7221.a arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o linemod.o move.o open.o point.o space.o subr.o
