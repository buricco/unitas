all:	setpgrp

setpgrp:	setpgrp.o
	$(CC) $(LDFLAGS) -o setpgrp setpgrp.o -lgen

setpgrp.o:	setpgrp.c
	$(CC) $(CFLAGS) -c -o setpgrp.o setpgrp.c

clean:
	rm -f setpgrp setpgrp.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin setpgrp
