CC ?= cc

all:	calendar calprog

calendar:	calendar.sh
	cp calendar.sh calendar

calprog:	calprog.o
	$(CC) $(LDFLAGS) -o calprog calprog.o

calprog.o:	calprog.c
	$(CC) $(CFLAGS) -c -o calprog.o calprog.c

clean:
	rm -f calendar calprog calprog.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin calendar
	sh ../install/sysinstall.sh $(ROOT)/usr/lib calprog
