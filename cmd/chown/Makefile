all:	chown

chown:	chown.o
	$(CC) $(LDFLAGS) -o chown chown.o -lgen

chown.o:	chown.c
	$(CC) $(CFLAGS) -c -o chown.o chown.c

clean:
	rm -f chown chown.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin chown
	ln -fs chown $(ROOT)/usr/bin/chgrp
