../libt300.a:	arc.o box.o circle.o close.o dot.o erase.o label.o line.o linmod.o move.o open.o point.o space.o subr.o
	$(AR) rc ../libt300.a arc.o box.o circle.o close.o dot.o erase.o label.o line.o linmod.o move.o open.o point.o space.o subr.o

arc.o:	arc.c
	$(CC) $(CFLAGS) -c -o arc.o arc.c

box.o:	box.c
	$(CC) $(CFLAGS) -c -o box.o box.c

circle.o:	circle.c
	$(CC) $(CFLAGS) -c -o circle.o circle.c

close.o:	close.c
	$(CC) $(CFLAGS) -c -o close.o close.c

dot.o:	dot.c
	$(CC) $(CFLAGS) -c -o dot.o dot.c

erase.o:	erase.c con.h
	$(CC) $(CFLAGS) -c -o erase.o erase.c

label.o:	label.c con.h
	$(CC) $(CFLAGS) -c -o label.o label.c

line.o:	line.c con.h
	$(CC) $(CFLAGS) -c -o line.o line.c

linmod.o:	linmod.c
	$(CC) $(CFLAGS) -c -o linmod.o linmod.c

move.o:	move.c
	$(CC) $(CFLAGS) -c -o move.o move.c

open.o:	open.c
	$(CC) $(CFLAGS) -c -o open.o open.c

point.o:	point.c
	$(CC) $(CFLAGS) -c -o point.o point.c

space.o:	space.c con.h
	$(CC) $(CFLAGS) -c -o space.o space.c

subr.o:	subr.c con.h
	$(CC) $(CFLAGS) -c -o subr.o subr.c

clean:
	rm -f ../libt300.a arc.o box.o circle.o close.o dot.o erase.o label.o line.o linmod.o move.o open.o point.o space.o subr.o
