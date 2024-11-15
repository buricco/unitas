CC ?= cc

bfs:	bfs.o compile.o
	$(CC) $(LDFLAGS) -o bfs bfs.o compile.o -lgen -lw

bfs.o:	bfs.c regexpr.h
	$(CC) $(CFLAGS) -c -o bfs.o bfs.c

compile.o:	compile.c regexpr.h
	$(CC) $(CFLAGS) -c -o compile.o compile.c

clean:
	rm -f bfs bfs.o compile.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin bfs
