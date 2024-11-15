CC ?= cc

crypt:	crypt.o
	$(CC) $(LDFLAGS) -o crypt crypt.o

crypt.o:	crypt.c
	$(CC) $(CFLAGS) -c -o crypt.o crypt.c

clean:
	rm -f crypt crypt.o

