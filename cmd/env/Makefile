all:	env

env:	env.o
	$(CC) $(LDFLAGS) -o env env.o -lgen

env.o:	env.c
	$(CC) $(CFLAGS) -c -o env.o env.c

clean:
	rm -f env env.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin env
