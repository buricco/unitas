all:	logins

logins:	logins.o
	$(CC) $(LDFLAGS) -o logins logins.o -lgen

logins.o:	logins.c
	$(CC) $(CFLAGS) -c -o logins.o logins.c

clean:
	rm -f logins logins.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin logins
