CC ?= cc

pwd:	pwd.o
	$(CC) $(LDFLAGS) -o pwd pwd.o

pwd.o:	pwd.c
	$(CC) $(CFLAGS) -c -o pwd.o pwd.c

clean:
	rm -f pwd pwd.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin pwd
