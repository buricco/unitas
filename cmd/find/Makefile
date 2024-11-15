all:	find

find:	find.o getdir.o gmatch.o
	$(CC) $(LDFLAGS) -o find find.o getdir.o gmatch.o

find.o:	find.c getdir.h
	$(CC) $(CFLAGS) -c -o find.o find.c

getdir.o:	getdir.c getdir.h
	$(CC) $(CFLAGS) -c -o getdir.o getdir.c

gmatch.o:	gmatch.c
	$(CC) $(CFLAGS) -c -o gmatch.o gmatch.c

clean:
	rm -f find find.o getdir.o gmatch.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin find
