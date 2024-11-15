all:	priocntl

priocntl:	priocntl.o
	$(CC) -o priocntl priocntl.o

priocntl.o:	priocntl.c
	$(CC) -c -o priocntl.o priocntl.c

clean:
	rm -f priocntl priocntl.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin priocntl
