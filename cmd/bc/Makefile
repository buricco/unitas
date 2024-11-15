all:	bc lib.b

bc:	y.tab.o
	$(CC) $(LDFLAGS) -o bc y.tab.o

y.tab.o:	y.tab.c
	$(CC) $(CFLAGS) -c -o y.tab.o y.tab.c

y.tab.c:	bc.y
	yacc bc.y

lib.b:	lib.b.data
	cp lib.b.data lib.b

clean:
	rm -f bc lib.b y.tab.c y.tab.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin bc
	sh ../install/sysinstall.sh $(ROOT)/usr/lib lib.b
