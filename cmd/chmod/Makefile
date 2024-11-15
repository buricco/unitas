all:	chmod

chmod:	chmod.o setmode.o
	$(CC) $(LDFLAGS) -o chmod chmod.o setmode.o

chmod.o:	chmod.c setmode.h
	$(CC) $(CCFLAGS) -c -o chmod.o chmod.c

setmode.o:	setmode.c setmode.h
	$(CC) $(CCFLAGS) -c -o setmode.o setmode.c

clean:
	rm -f chmod chmod.o setmode.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin chmod
