all:	ct cu uuglist uucp uuname uustat uux uudecode uuencode bnuconvert remote.unknown uucheck uucleanup uusched uucico uuxqt

ct:	ct.o callers.o getargs.o line.o uucpdefs.o ulockf.o conn.o interface.o sysfiles.o strsave.o strecpy.o stoa.o libdk.a
	$(CC) $(LDFLAGS) -o ct ct.o callers.o getargs.o line.o uucpdefs.o ulockf.o conn.o interface.o sysfiles.o strsave.o strecpy.o stoa.o -L. -ldk -lnsl

cu:	cu.o callers.o getargs.o line.o uucpdefs.o ulockf.o conn.o interface.o strsave.o sysfiles.o strecpy.o stoa.o libdk.a
	$(CC) $(LDFLAGS) -o cu cu.o callers.o getargs.o line.o uucpdefs.o ulockf.o conn.o interface.o strsave.o sysfiles.o strecpy.o stoa.o -L. -ldk -lnsl

uuglist:	grades.o cpmv.o getargs.o getpwinfo.o strsave.o uuglist.o uucpdefs.o expfile.o uucpname.o
	$(CC) $(LDFLAGS) -o uuglist grades.o cpmv.o getargs.o getpwinfo.o strsave.o uuglist.o uucpdefs.o expfile.o uucpname.o

uucp:	uucpdefs.o uucp.o gwd.o permission.o getargs.o getprm.o uucpname.o versys.o gtcfile.o grades.o chremdir.o mailst.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o gnamef.o systat.o sysfiles.o strsave.o
	$(CC) $(LDFLAGS) -o uucp uucpdefs.o uucp.o gwd.o permission.o getargs.o getprm.o uucpname.o versys.o gtcfile.o grades.o chremdir.o mailst.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o gnamef.o systat.o sysfiles.o strsave.o

uuname:	uuname.o uucpname.o uucpdefs.o getpwinfo.o sysfiles.o strsave.o
	$(CC) $(LDFLAGS) -o uuname uuname.o uucpname.o uucpdefs.o getpwinfo.o sysfiles.o strsave.o

uustat:	uustat.o gnamef.o expfile.o uucpdefs.o getpwinfo.o ulockf.o getargs.o utility.o uucpname.o versys.o strsave.o sysfiles.o cpmv.o mailst.o permission.o
	$(CC) $(LDFLAGS) -o uustat uustat.o gnamef.o expfile.o uucpdefs.o getpwinfo.o ulockf.o getargs.o utility.o uucpname.o versys.o strsave.o sysfiles.o cpmv.o mailst.o permission.o

uux:	uucpdefs.o uux.o mailst.o gwd.o permission.o getargs.o getprm.o uucpname.o versys.o gtcfile.o grades.o chremdir.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o gnamef.o systat.o sysfiles.o strsave.o
	$(CC) $(LDFLAGS) -o uux uucpdefs.o uux.o mailst.o gwd.o permission.o getargs.o getprm.o uucpname.o versys.o gtcfile.o grades.o chremdir.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o gnamef.o systat.o sysfiles.o strsave.o

uudecode:	uudecode.o
	$(CC) $(LDFLAGS) -o uudecode uudecode.o

uuencode:	uuencode.o
	$(CC) $(LDFLAGS) -o uuencode uuencode.o

bnuconvert:	bnuconvert.o uucpdefs.o grades.o strsave.o getpwinfo.o getargs.o cpmv.o chremdir.o expfile.o gename.o gnamef.o gtcfile.o logent.o systat.o ulockf.o utility.o uucpname.o
	$(CC) $(LDFLAGS) -o bnuconvert bnuconvert.o uucpdefs.o grades.o strsave.o getpwinfo.o getargs.o cpmv.o chremdir.o expfile.o gename.o gnamef.o gtcfile.o logent.o systat.o ulockf.o utility.o uucpname.o

remote.unknown:	unknown.o
	$(CC) $(LDFLAGS) -o remote.unknown unknown.o

uucheck:	uucheck.o uucpname.o
	$(CC) $(LDFLAGS) -o uucheck uucheck.o uucpname.o

uucleanup:	uucleanup.o gnamef.o expfile.o uucpdefs.o getpwinfo.o uucpname.o ulockf.o getargs.o cpmv.o utility.o
	$(CC) $(LDFLAGS) -o uucleanup uucleanup.o gnamef.o expfile.o uucpdefs.o getpwinfo.o uucpname.o ulockf.o getargs.o cpmv.o utility.o

uusched:	uusched.o gnamef.o expfile.o uucpdefs.o getpwinfo.o ulockf.o systat.o getargs.o utility.o limits.o permission.o uucpname.o
	$(CC) $(LDFLAGS) -o uusched uusched.o gnamef.o expfile.o uucpdefs.o getpwinfo.o ulockf.o systat.o getargs.o utility.o limits.o permission.o uucpname.o

uucico:	uucpdefs.o uucico.o conn.o callers.o cntrl.o pk0.o pk1.o anlwrk.o permission.o getargs.o gnxseq.o pkdefs.o imsg.o gtcfile.o grades.o mailst.o uucpname.o line.o chremdir.o interface.o statlog.o strecpy.o stoa.o perfstat.o account.o security.o limits.o dio.o eio.o gio.o xio.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o versys.o gnamef.o systat.o sysfiles.o strsave.o libdk.a
	$(CC) $(LDFLAGS) -o uucico uucpdefs.o uucico.o conn.o callers.o cntrl.o pk0.o pk1.o anlwrk.o permission.o getargs.o gnxseq.o pkdefs.o imsg.o gtcfile.o grades.o mailst.o uucpname.o line.o chremdir.o interface.o statlog.o strecpy.o stoa.o perfstat.o account.o security.o limits.o dio.o eio.o gio.o xio.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o versys.o gnamef.o systat.o sysfiles.o strsave.o -L. -ldk -lnsl

uuxqt:	uucpdefs.o uuxqt.o mailst.o getprm.o uucpname.o permission.o getargs.o gtcfile.o grades.o shio.o chremdir.o account.o perfstat.o statlog.o security.o limits.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o versys.o gnamef.o systat.o sysfiles.o strsave.o
	$(CC) $(LDFLAGS) -o uuxqt uucpdefs.o uuxqt.o mailst.o getprm.o uucpname.o permission.o getargs.o gtcfile.o grades.o shio.o chremdir.o account.o perfstat.o statlog.o security.o limits.o utility.o cpmv.o expfile.o gename.o getpwinfo.o ulockf.o xqt.o logent.o versys.o gnamef.o systat.o sysfiles.o strsave.o

libdk.a:	dkbreak.o dkdial.o dkerr.o dkminor.o dtnamer.o
	$(AR) rc libdk.a dkbreak.o dkdial.o dkerr.o dkminor.o dtnamer.o

dkbreak.o:	dkbreak.c dk.h
	$(CC) $(CFLAGS) -I. -c -o dkbreak.o dkbreak.c

dkdial.o:	dkdial.c dk.h sysexits.h
	$(CC) $(CFLAGS) -I. -c -o dkdial.o dkdial.c

dkerr.o:	dkerr.c dk.h sysexits.h
	$(CC) $(CFLAGS) -I. -c -o dkerr.o dkerr.c

dkminor.o:	dkminor.c dk.h
	$(CC) $(CFLAGS) -I. -c -o dkminor.o dkminor.c

dtnamer.o:	dtnamer.c dk.h
	$(CC) $(CFLAGS) -I. -c -o dtnamer.o dtnamer.c

account.o:	account.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o account.o account.c

anlwrk.o:	anlwrk.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o anlwrk.o anlwrk.c

bnuconvert.o:	bnuconvert.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o bnuconvert.o bnuconvert.c

callers.o:	callers.c uucp.h parms.h dk.h
	$(CC) $(CFLAGS) -I. -c -o callers.o callers.c

chremdir.o:	chremdir.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o chremdir.o chremdir.c

cntrl.o:	cntrl.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o cntrl.o cntrl.c

conn.o:	conn.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o conn.o conn.c

cpmv.o:	cpmv.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o cpmv.o cpmv.c

ct.o:	ct.c uucp.h parms.h sysfiles.h dk.h
	$(CC) $(CFLAGS) -I. -c -o ct.o ct.c

cu.o:	cu.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o cu.o cu.c

dio.o:	dio.c uucp.h parms.h dk.h
	$(CC) $(CFLAGS) -I. -c -o dio.o dio.c

eio.o:	eio.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o eio.o eio.c

expfile.o:	expfile.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o expfile.o expfile.c

gename.o:	gename.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o gename.o gename.c

getargs.o:	getargs.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o getargs.o getargs.c

getprm.o:	getprm.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o getprm.o getprm.c

getpwinfo.o:	getpwinfo.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o getpwinfo.o getpwinfo.c

gio.o:	gio.c uucp.h parms.h pk.h
	$(CC) $(CFLAGS) -I. -c -o gio.o gio.c

gnamef.o:	gnamef.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o gnamef.o gnamef.c

gnxseq.o:	gnxseq.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o gnxseq.o gnxseq.c

grades.o:	grades.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o grades.o grades.c

gtcfile.o:	gtcfile.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o gtcfile.o gtcfile.c

gwd.o:	gwd.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o gwd.o gwd.c

imsg.o:	imsg.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o imsg.o imsg.c

interface.o:	interface.c uucp.h parms.h dk.h
	$(CC) $(CFLAGS) -I. -c -o interface.o interface.c

limits.o:	limits.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o limits.o limits.c

line.o:	line.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o line.o line.c

logent.o:	logent.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o logent.o logent.c

mailst.o:	mailst.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o mailst.o mailst.c

perfstat.o:	perfstat.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o perfstat.o perfstat.c

permission.o:	permission.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o permission.o permission.c

pk0.o:	pk0.c uucp.h parms.h pk.h
	$(CC) $(CFLAGS) -I. -c -o pk0.o pk0.c

pk1.o:	pk1.c uucp.h parms.h pk.h
	$(CC) $(CFLAGS) -I. -c -o pk1.o pk1.c

pkdefs.o:	pkdefs.c uucp.h parms.h pk.h
	$(CC) $(CFLAGS) -I. -c -o pkdefs.o pkdefs.c

security.o:	security.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o security.o security.c

shio.o:	shio.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o shio.o shio.c

statlog.o:	statlog.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o statlog.o statlog.c

stoa.o:	stoa.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o stoa.o stoa.c

strecpy.o:	strecpy.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o strecpy.o strecpy.c

strsave.o:	strsave.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o strsave.o strsave.c

sysfiles.o:	sysfiles.c uucp.h parms.h sysfiles.h
	$(CC) $(CFLAGS) -I. -c -o sysfiles.o sysfiles.c

systat.o:	systat.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o systat.o systat.c

ulockf.o:	ulockf.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o ulockf.o ulockf.c

unknown.o:	unknown.c
	$(CC) $(CFLAGS) -I. -c -o unknown.o unknown.c

utility.o:	utility.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o utility.o utility.c

uucheck.o:	uucheck.c uucp.h parms.h permission.c sysfiles.h
	$(CC) $(CFLAGS) -I. -c -o uucheck.o uucheck.c

uucico.o:	uucico.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o uucico.o uucico.c

uucleanup.o:	uucleanup.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uucleanup.o uucleanup.c

uucp.o:	uucp.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uucp.o uucp.c

uucpdefs.o:	uucpdefs.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uucpdefs.o uucpdefs.c

uucpname.o:	uucpname.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uucpname.o uucpname.c

uudecode.o:	uudecode.c
	$(CC) $(CFLAGS) -I. -c -o uudecode.o uudecode.c

uuencode.o:	uuencode.c
	$(CC) $(CFLAGS) -I. -c -o uuencode.o uuencode.c

uuglist.o:	uuglist.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uuglist.o uuglist.c

uuname.o:	uuname.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uuname.o uuname.c

uusched.o:	uusched.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uusched.o uusched.c

uustat.o:	uustat.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uustat.o uustat.c

uux.o:	uux.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o uux.o uux.c

uuxqt.o:	uuxqt.c uucp.h parms.h log.h
	$(CC) $(CFLAGS) -I. -c -o uuxqt.o uuxqt.c

versys.o:	versys.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o versys.o versys.c

xio.o:	xio.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o xio.o xio.c

xqt.o:	xqt.c uucp.h parms.h
	$(CC) $(CFLAGS) -I. -c -o xqt.o xqt.c

clean:
	rm -f libdk.a dkbreak.o dkdial.o dkerr.o dkminor.o dtnamer.o
	rm -f account.o anlwrk.o bnuconvert.o callers.o chremdir.o cntrl.o   \
		conn.o cpmv.o ct.o cu.o dio.o eio.o expfile.o gename.o       \
		getargs.o getprm.o getpwinfo.o gio.o gnamef.o gnxseq.o       \
		grades.o gtcfile.o gwd.o imsg.o interface.o limits.o line.o  \
		logent.o mailst.o perfstat.o permission.o pk0.o pk1.o        \
		pkdefs.o security.o shio.o statlog.o stoa.o strecpy.o        \
		strsave.o sysfiles.o systat.o ulockf.o unknown.o utility.o   \
		uucheck.o uucico.o uucleanup.o uucp.o uucpdefs.o uucpname.o  \
		uudecode.o uuencode.o uuglist.o uuname.o uusched.o uustat.o  \
		uux.o uuxqt.o versys.o xio.o xqt.o
	rm -f ct cu uuglist uucp uuname uustat uux uudecode uuencode         \
		bnuconvert remote.unknown uucheck uucleanup uusched uucico   \
		uuxqt
