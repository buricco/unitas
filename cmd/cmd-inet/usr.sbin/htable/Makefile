htable:	htable.o y.tab.o scan.o y.tab.c y.tab.h scan.c
	$(CC) $(LDFLAGS) -o htable htable.o y.tab.o scan.o -lsocket -lnsl

htable.o:	htable.c htable.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -DBSD_COMP -c -o htable.o htable.c

y.tab.o:	y.tab.c htable.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -DBSD_COMP -c -o y.tab.o y.tab.c

scan.o:	scan.c y.tab.h htable.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -DBSD_COMP -c -o scan.o scan.c

y.tab.c y.tab.h:	parse.y
	yacc -d parse.y

scan.c:	scan.l
	lex -t scan.l > scan.c

clean:
	rm -f htable htable.o y.tab.o scan.o y.tab.c y.tab.h scan.c
