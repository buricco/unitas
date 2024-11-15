CC ?= cc

fdetach:	fdetach.o
	$(CC) $(LDFLAGS) -o fdetach fdetach.o

fdetach.o:	fdetach.c
	$(CC) $(CFLAGS) -c -o fdetach.o fdetach.c

clean:
	rm -f fdetach fdetach.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin fdetach
