CC ?= cc
AR ?= ar

libnls.a:	nlsdata.o nlsenv.o nlsrequest.o
	$(AR) crv libnls.a nlsdata.o nlsenv.o nlsrequest.o

nlsdata.o:	nlsdata.c
	$(CC) $(CFLAGS) -c -o nlsdata.o nlsdata.c

nlsenv.o:	nlsenv.c
	$(CC) $(CFLAGS) -c -o nlsenv.o nlsenv.c

nlsrequest.o:	nlsrequest.c
	$(CC) $(CFLAGS) -c -o nlsrequest.o nlsrequest.c

clean:
	rm -f libnls.a nlsdata.o nlsenv.o nlsrequest.o
