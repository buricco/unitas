all:	du

du:	du.o getdir.o
	$(CC) $(LDFLAGS) -o du du.o getdir.o -lgen

du.o:	du.c getdir.h
	$(CC) $(CFLAGS) -c -o du.o du.c

getdir.o:	getdir.c getdir.h
	$(CC) $(CFLAGS) -c -o getdir.o getdir.c

clean:
	rm -f du du.o getdir.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin du
