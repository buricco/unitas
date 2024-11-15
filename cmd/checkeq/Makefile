CC ?= cc

checkeq:	checkeq.o
	$(CC) $(LDFLAGS) -o checkeq checkeq.o

checkeq.o:	checkeq.c
	$(CC) $(CFLAGS) -c -o checkeq.o checkeq.c

clean:
	rm -f checkeq checkeq.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin checkeq
