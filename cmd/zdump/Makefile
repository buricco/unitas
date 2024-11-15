CC ?= cc

zdump:	zdump.o
	$(CC) $(LDFLAGS) -o zdump zdump.o

zdump.o:	zdump.c
	$(CC) $(CFLAGS) -c -o zdump.o zdump.c

clean:
	rm -f zdump zdump.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin zdump
