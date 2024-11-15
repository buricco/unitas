CC ?= cc

comm:	comm.o
	$(CC) $(LDFLAGS) -o comm comm.o

comm.o:	comm.c
	$(CC) $(CFLAGS) -c -o comm.o comm.c

clean:
	rm -f comm comm.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin comm
