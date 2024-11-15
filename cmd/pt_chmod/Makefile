CC ?= cc

pt_chmod:	pt_chmod.o
	$(CC) $(LDFLAGS) -o pt_chmod pt_chmod.o

pt_chmod.o:	pt_chmod.c
	$(CC) $(CFLAGS) -c -o pt_chmod.o pt_chmod.c

clean:
	rm -f pt_chmod pt_chmod.o
