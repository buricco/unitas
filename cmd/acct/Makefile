# uso: diskusg was removed from illumos, probably because it was too tied into
#      low-level deets of the S5 native filesystem.  Even an early OpenSolaris
#      version does not build on modern Solaris.  The code remains but is now
#      disabled.

all:	acctcms acctcom acctcon acctcon1 acctcon2 acctdisk acctdusg acctmerg \
	accton acctprc acctprc1 acctprc2 acctwtmp closewtmp fwtmp wtmpfix    \
	utmp2wtmp acct chargefee ckpacct dodisk lastlogin monacct nulladm    \
	prctmp prdaily prtacct remove runacct shutacct startup turnacct

lib/a.a:
	make -C lib

acct:	acct.sh
	cp acct.sh acct

chargefee:	chargefee.sh
	cp chargefee.sh chargefee

ckpacct:	ckpacct.sh
	cp ckpacct.sh ckpacct

dodisk:	dodisk.sh
	cp dodisk.sh dodisk

lastlogin:	lastlogin.sh
	cp lastlogin.sh lastlogin

monacct:	monacct.sh
	cp monacct.sh monacct

nulladm:	nulladm.sh
	cp nulladm.sh nulladm

prctmp:	prctmp.sh
	cp prctmp.sh prctmp

prdaily:	prdaily.sh
	cp prdaily.sh prdaily

prtacct:	prtacct.sh
	cp prtacct.sh prtacct

remove:	remove.sh
	cp remove.sh remove

runacct:	runacct.sh
	cp runacct.sh runacct

shutacct:	shutacct.sh
	cp shutacct.sh shutacct

startup:	startup.sh
	cp startup.sh startup

turnacct:	turnacct.sh
	cp turnacct.sh turnacct

acctcms:	acctcms.o lib/a.a
	$(CC) $(LDFLAGS) -o acctcms acctcms.o lib/a.a

acctcom:	acctcom.o lib/a.a
	$(CC) $(LDFLAGS) -o acctcom acctcom.o lib/a.a -lgen

acctcon:	acctcon.o lib/a.a
	$(CC) $(LDFLAGS) -o acctcon acctcon.o lib/a.a

acctcon1:	acctcon1.o lib/a.a
	$(CC) $(LDFLAGS) -o acctcon1 acctcon1.o lib/a.a

acctcon2:	acctcon2.o lib/a.a
	$(CC) $(LDFLAGS) -o acctcon2 acctcon2.o lib/a.a

acctdisk:	acctdisk.o lib/a.a
	$(CC) $(LDFLAGS) -o acctdisk acctdisk.o lib/a.a

acctdusg:	acctdusg.o lib/a.a
	$(CC) $(LDFLAGS) -o acctdusg acctdusg.o lib/a.a

acctmerg:	acctmerg.o lib/a.a
	$(CC) $(LDFLAGS) -o acctmerg acctmerg.o lib/a.a

accton:	accton.o lib/a.a
	$(CC) $(LDFLAGS) -o accton accton.o lib/a.a

acctprc:	acctprc.o lib/a.a
	$(CC) $(LDFLAGS) -o acctprc acctprc.o lib/a.a

acctprc1:	acctprc1.o lib/a.a
	$(CC) $(LDFLAGS) -o acctprc1 acctprc1.o lib/a.a

acctprc2:	acctprc2.o lib/a.a
	$(CC) $(LDFLAGS) -o acctprc2 acctprc2.o lib/a.a

acctwtmp:	acctwtmp.o lib/a.a
	$(CC) $(LDFLAGS) -o acctwtmp acctwtmp.o lib/a.a

closewtmp:	closewtmp.o lib/a.a
	$(CC) $(LDFLAGS) -o closewtmp closewtmp.o lib/a.a

fwtmp:	fwtmp.o lib/a.a
	$(CC) $(LDFLAGS) -o fwtmp fwtmp.o lib/a.a

wtmpfix:	wtmpfix.o lib/a.a
	$(CC) $(LDFLAGS) -o wtmpfix wtmpfix.o lib/a.a

utmp2wtmp:	utmp2wtmp.o lib/a.a
	$(CC) $(LDFLAGS) -o utmp2wtmp utmp2wtmp.o lib/a.a

acctcms.o:	acctcms.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctcms.o acctcms.c

acctcom.o:	acctcom.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctcom.o acctcom.c

acctcon.o:	acctcon.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctcon.o acctcon.c

acctcon1.o:	acctcon1.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctcon1.o acctcon1.c

acctcon2.o:	acctcon2.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctcon2.o acctcon2.c

acctdisk.o:	acctdisk.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctdisk.o acctdisk.c

acctdusg.o:	acctdusg.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctdusg.o acctdusg.c

acctmerg.o:	acctmerg.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctmerg.o acctmerg.c

accton.o:	accton.c acctdef.h
	$(CC) $(CFLAGS) -c -o accton.o accton.c

acctprc.o:	acctprc.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctprc.o acctprc.c

acctprc1.o:	acctprc1.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctprc1.o acctprc1.c

acctprc2.o:	acctprc2.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctprc2.o acctprc2.c

acctwtmp.o:	acctwtmp.c acctdef.h
	$(CC) $(CFLAGS) -c -o acctwtmp.o acctwtmp.c

closewtmp.o:	closewtmp.c
	$(CC) $(CFLAGS) -c -o closewtmp.o closewtmp.c

fwtmp.o:	fwtmp.c acctdef.h
	$(CC) $(CFLAGS) -c -o fwtmp.o fwtmp.c

wtmpfix.o:	wtmpfix.c acctdef.h
	$(CC) $(CFLAGS) -c -o wtmpfix.o wtmpfix.c

utmp2wtmp.o:	utmp2wtmp.c
	$(CC) $(CFLAGS) -c -o utmp2wtmp.o utmp2wtmp.c

clean:
	make -C lib clean
	rm -f acctcms acctcom acctcon acctcon1 acctcon2 acctdisk acctdusg    \
		acctmerg accton acctprc acctprc1 acctprc2 acctwtmp closewtmp \
		fwtmp wtmpfix utmp2wtmp acct chargefee ckpacct dodisk        \
		lastlogin monacct nulladm prctmp prdaily prtacct remove      \
		runacct shutacct startup turnacct acctcms.o acctcom.o        \
		acctcon.o acctcon1.o acctcon2.o acctdisk.o acctdusg.o        \
		acctmerg.o accton.o acctprc.o acctprc1.o acctprc2.o          \
		acctwtmp.o closewtmp.o fwtmp.o wtmpfix.o utmp2wtmp.o

install:
	sh ../install/sysinstall.sh $(ROOT)/etc/init.d acct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctcms
	sh ../install/sysinstall.sh $(ROOT)/usr/bin acctcom
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctcon
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctcon1
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctcon2
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctdisk
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctdusg
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctmerg
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct accton
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctprc
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctprc1
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctprc2
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct acctwtmp
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct closewtmp
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct fwtmp
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct wtmpfix
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct utmp2wtmp
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct chargefee
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct ckpacct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct dodisk
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct lastlogin
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct monacct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct nulladm
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct prctmp
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct prdaily
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct prtacct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct remove
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct runacct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct shutacct
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct startup
	sh ../install/sysinstall.sh $(ROOT)/usr/lib/acct turnacct
	sh ../install/sysinstall.sh $(ROOT)/etc/acct holidays
