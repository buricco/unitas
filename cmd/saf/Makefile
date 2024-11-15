all:	sac sacadm pmadm

sac:	sac.o readtab.o global.o log.o misc.o util1.o
	$(CC) $(LDFLAGS) -o sac sac.o readtab.o global.o log.o misc.o util1.o -lnsl

sacadm:	sacadm.o admutil.o util2.o
	$(CC) $(LDFLAGS) -o sacadm sacadm.o admutil.o util2.o -lnsl

pmadm:	pmadm.o admutil.o util2.o
	$(CC) $(LDFLAGS) -o pmadm pmadm.o admutil.o util2.o -lnsl

sac.o:	sac.c msgs.h extern.h misc.h structs.h
	$(CC) $(CFLAGS) -fno-builtin -c -o sac.o sac.c

readtab.o:	readtab.c misc.h msgs.h structs.h extern.h
	$(CC) $(CFLAGS) -fno-builtin -c -o readtab.o readtab.c

global.o:	global.c misc.h structs.h
	$(CC) $(CFLAGS) -fno-builtin -c -o global.o global.c

log.o:	log.c extern.h misc.h msgs.h structs.h
	$(CC) $(CFLAGS) -fno-builtin -c -o log.o log.c

misc.o:	misc.c misc.h msgs.h extern.h adm.h structs.h
	$(CC) $(CFLAGS) -fno-builtin -c -o misc.o misc.c

util1.o:	util.c extern.h misc.h structs.h msgs.h
	$(CC) $(CFLAGS) -DSAC -fno-builtin -c -o util1.o util.c

util2.o:	util.c extern.h misc.h structs.h
	$(CC) $(CFLAGS) -USAC -fno-builtin -c -o util2.o util.c

sacadm.o:	sacadm.c misc.h structs.h adm.h extern.h
	$(CC) $(CFLAGS) -fno-builtin -c -o sacadm.o sacadm.c

admutil.o:	admutil.c misc.h structs.h extern.h
	$(CC) $(CFLAGS) -fno-builtin -c -o admutil.o admutil.c

pmadm.o:	pmadm.c extern.h misc.h structs.h
	$(CC) $(CFLAGS) -fno-builtin -c -o pmadm.o pmadm.c

clean:
	rm -f sac sacadm pmadm sac.o readtab.o global.o log.o misc.o util1.o util2.o sacadm.o admutil.o pmadm.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin pmadm
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin sacadm
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/saf sac
	ln -fs ../lib/saf/sac $(ROOT)/usr/etc/sac
