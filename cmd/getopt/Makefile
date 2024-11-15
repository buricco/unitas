CC ?= cc

all:	getopt getoptcvt

getopt:	getopt.o
	$(CC) $(LDFLAGS) -o getopt getopt.o

getopt.o:	getopt.c
	$(CC) $(CFLAGS) -c -o getopt.o getopt.c

getoptcvt:	getoptcvt.sh
	cp getoptcvt.sh getoptcvt

clean:
	rm -f getopt getopt.o getoptcvt

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin getopt
	sh ../install/sysinstall.sh $(ROOT)/usr/lib getoptcvt
