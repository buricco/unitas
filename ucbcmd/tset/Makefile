tset:	tset.o
	$(CC) $(LDFLAGS) -o tset tset.o -lcurses

tset.o:	tset.c tset.delays.h
	$(CC) $(CFLAGS) -c -o tset.o tset.c

clean:
	rm -f tset tset.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb tset
