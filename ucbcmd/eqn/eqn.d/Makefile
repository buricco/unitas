eqn:	diacrit.o eqnbox.o font.o fromto.o funny.o glob.o integral.o io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o shift.o size.o sqrt.o text.o y.tab.o
	$(CC) $(LDFLAGS) -o eqn diacrit.o eqnbox.o font.o fromto.o funny.o glob.o integral.o io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o shift.o size.o sqrt.o text.o y.tab.o

diacrit.o:	../diacrit.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o diacrit.o ../diacrit.c

eqnbox.o:	../eqnbox.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o eqnbox.o ../eqnbox.c

font.o:	../font.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o font.o ../font.c

fromto.o:	../fromto.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o fromto.o ../fromto.c

funny.o:	../funny.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o funny.o ../funny.c

glob.o:	../glob.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o glob.o ../glob.c

integral.o:	../integral.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o integral.o ../integral.c

io.o:	../io.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o io.o ../io.c

lex.o:	../lex.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o lex.o ../lex.c

lookup.o:	../lookup.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o lookup.o ../lookup.c

mark.o:	../mark.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o mark.o ../mark.c

matrix.o:	../matrix.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o matrix.o ../matrix.c

move.o:	../move.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o move.o ../move.c

over.o:	../over.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o over.o ../over.c

paren.o:	../paren.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o paren.o ../paren.c

pile.o:	../pile.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o pile.o ../pile.c

shift.o:	../shift.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o shift.o ../shift.c

size.o:	../size.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o size.o ../size.c

sqrt.o:	../sqrt.c ../e.h
	$(CC) $(CFLAGS) -I. -I.. -c -o sqrt.o ../sqrt.c

text.o:	../text.c ../e.h y.tab.h
	$(CC) $(CFLAGS) -I. -I.. -c -o text.o ../text.c

y.tab.o:	y.tab.c
	$(CC) $(CFLAGS) -I. -I.. -c -o y.tab.o y.tab.c

y.tab.c y.tab.h:	../e.y
	yacc -d ../e.y

clean:
	rm -f eqn diacrit.o eqnbox.o font.o fromto.o funny.o glob.o integral.o io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o shift.o size.o sqrt.o text.o y.tab.o y.tab.c y.tab.h
