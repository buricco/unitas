CC ?= cc

users:	users.o
	$(CC) $(LDFLAGS) -o users users.o

users.o:	users.c
	$(CC) $(CFLAGS) -c -o users.o users.c

clean:
	rm -f users users.o

