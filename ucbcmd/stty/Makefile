stty:	stty.o sttyparse.o sttytable.o
	$(CC) $(LDFLAGS) -o stty stty.o sttyparse.o sttytable.o

stty.o:	stty.c stty.h
	$(CC) $(CFLAGS) -c -o stty.o stty.c

sttyparse.o:	sttyparse.c stty.h
	$(CC) $(CFLAGS) -c -o sttyparse.o sttyparse.c

sttytable.o:	sttytable.c stty.h
	$(CC) $(CFLAGS) -c -o sttytable.o sttytable.c

clean:
	rm -f stty stty.o sttyparse.o sttytable.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb stty
