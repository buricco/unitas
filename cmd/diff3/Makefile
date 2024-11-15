CC ?= cc

all:	diff3 diff3prog

diff3:	diff3.sh
	cp diff3.sh diff3

diff3prog:	diff3prog.o
	$(CC) $(LDFLAGS) -o diff3prog diff3prog.o

diff3prog.o:	diff3prog.c
	$(CC) $(CFLAGS) -c -o diff3prog.o diff3prog.c

clean:
	rm -f diff3 diff3prog diff3prog.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin diff3
	sh ../install/sysinstall.sh $(ROOT)/usr/lib diff3prog
