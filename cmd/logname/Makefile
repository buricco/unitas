CC ?= cc

logname:	logname.o
	$(CC) $(LDFLAGS) -o logname logname.o

logname.o:	logname.c
	$(CC) $(CFLAGS) -c -o logname.o logname.c

clean:
	rm -f logname logname.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin logname
