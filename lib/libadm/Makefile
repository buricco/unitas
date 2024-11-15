libadm.a:	cftime.o ckdate.o ckgid.o ckint.o ckitem.o ckkeywd.o         \
	ckpath.o ckrange.o ckstr.o cktime.o ckuid.o ckyorn.o closefrom.o     \
	data.o devattr.o devreserv.o devtab.o dgrpent.o fulldevnm.o getdev.o \
	getdgrp.o getinput.o getopt.o getpass.o getvol.o listdev.o           \
	listdgrp.o mkdirp.o pkginfo.o pkgnmchk.o pkgparam.o putdev.o         \
	putdgrp.o puterror.o puthelp.o putprmpt.o puttext.o rdwr_vtoc.o      \
	regexp.o sigsend.o space.o strlcat.o strlcpy.o
	$(AR) cr libadm.a cftime.o ckdate.o ckgid.o ckint.o ckitem.o         \
		ckkeywd.o ckpath.o ckrange.o ckstr.o cktime.o ckuid.o        \
		ckyorn.o closefrom.o data.o devattr.o devreserv.o devtab.o   \
		dgrpent.o fulldevnm.o getdev.o getdgrp.o getinput.o getopt.o \
		getpass.o getvol.o listdev.o listdgrp.o mkdirp.o pkginfo.o   \
		pkgnmchk.o pkgparam.o putdev.o putdgrp.o puterror.o          \
		puthelp.o putprmpt.o puttext.o rdwr_vtoc.o regexp.o          \
		sigsend.o space.o strlcat.o strlcpy.o

cftime.o:	cftime.c
	$(CC) $(CFLAGS) -c -o cftime.o cftime.c

ckdate.o:	ckdate.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h      \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckdate.o ckdate.c

ckgid.o:	ckgid.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h       \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckgid.o ckgid.c

ckint.o:	ckint.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h       \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckint.o ckint.c

ckitem.o:	ckitem.c valtools.h libadm.h vtoc.h dklabel.h pkgstrct.h     \
	pkginfo.h install.h
	$(CC) $(CFLAGS) -c -o ckitem.o ckitem.c

ckkeywd.o:	ckkeywd.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h     \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckkeywd.o ckkeywd.c

ckpath.o:	ckpath.c valtools.h libadm.h vtoc.h dklabel.h pkgstrct.h     \
	pkginfo.h install.h
	$(CC) $(CFLAGS) -c -o ckpath.o ckpath.c

ckrange.o:	ckrange.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h     \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckrange.o ckrange.c

ckstr.o:	ckstr.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h       \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckstr.o ckstr.c

cktime.o:	cktime.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h      \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o cktime.o cktime.c

ckuid.o:	ckuid.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h       \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckuid.o ckuid.c

ckyorn.o:	ckyorn.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h      \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o ckyorn.o ckyorn.c

closefrom.o:	closefrom.c
	$(CC) $(CFLAGS) -c -o closefrom.o closefrom.c

data.o:	data.c
	$(CC) $(CFLAGS) -c -o data.o data.c

devattr.o:	devattr.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o devattr.o devattr.c

devreserv.o:	devreserv.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o devreserv.o devreserv.c

devtab.o:	devtab.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o devtab.o devtab.c

dgrpent.o:	dgrpent.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o dgrpent.o dgrpent.c

fulldevnm.o:	fulldevnm.c vfstab.h libadm.h vtoc.h dklabel.h pkgstrct.h    \
	pkginfo.h valtools.h install.h
	$(CC) $(CFLAGS) -c -o fulldevnm.o fulldevnm.c

getdev.o:	getdev.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o getdev.o getdev.c

getdgrp.o:	getdgrp.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o getdgrp.o getdgrp.c

getinput.o:	getinput.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h    \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o getinput.o getinput.c

getopt.o:	getopt.c
	$(CC) $(CFLAGS) -c -o getopt.o getopt.c

getpass.o:	getpass.c
	$(CC) $(CFLAGS) -c -o getpass.o getpass.c

getvol.o:	getvol.c devmgmt.h libadm.h vtoc.h dklabel.h pkgstrct.h      \
	pkginfo.h valtools.h install.h
	$(CC) $(CFLAGS) -c -o getvol.o getvol.c

listdev.o:	listdev.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o listdev.o listdev.c

listdgrp.o:	listdgrp.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o listdgrp.o listdgrp.c

mkdirp.o:	mkdirp.c
	$(CC) $(CFLAGS) -c -o mkdirp.o mkdirp.c

pkginfo.o:	pkginfo.c pkginfo.h pkgstrct.h pkglocs.h libadm.h vtoc.h     \
	dklabel.h valtools.h install.h
	$(CC) $(CFLAGS) -c -o pkginfo.o pkginfo.c

pkgnmchk.o:	pkgnmchk.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h    \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o pkgnmchk.o pkgnmchk.c

pkgparam.o:	pkgparam.c pkgstrct.h pkginfo.h pkglocs.h libadm.h vtoc.h    \
	dklabel.h valtools.h install.h
	$(CC) $(CFLAGS) -c -o pkgparam.o pkgparam.c

putdev.o:	putdev.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o putdev.o putdev.c

putdgrp.o:	putdgrp.c devmgmt.h devtab.h
	$(CC) $(CFLAGS) -c -o putdgrp.o putdgrp.c

puterror.o:	puterror.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h    \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o puterror.o puterror.c

puthelp.o:	puthelp.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h     \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o puthelp.o puthelp.c

putprmpt.o:	putprmpt.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h    \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o putprmpt.o putprmpt.c

puttext.o:	puttext.c libadm.h vtoc.h dklabel.h pkgstrct.h pkginfo.h     \
	valtools.h install.h
	$(CC) $(CFLAGS) -c -o puttext.o puttext.c

rdwr_vtoc.o:	rdwr_vtoc.c vtoc.h dklabel.h
	$(CC) $(CFLAGS) -c -o rdwr_vtoc.o rdwr_vtoc.c

regexp.o:	regexp.c regexp.h
	$(CC) $(CFLAGS) -c -o regexp.o regexp.c

sigsend.o:	sigsend.c
	$(CC) $(CFLAGS) -c -o sigsend.o sigsend.c

space.o:	space.c
	$(CC) $(CFLAGS) -c -o space.o space.c

strlcat.o:	strlcat.c
	$(CC) $(CFLAGS) -c -o strlcat.o strlcat.c

strlcpy.o:	strlcpy.c
	$(CC) $(CFLAGS) -c -o strlcpy.o strlcpy.c

clean:
	rm -f libadm.a cftime.o ckdate.o ckgid.o ckint.o ckitem.o ckkeywd.o  \
		ckpath.o ckrange.o ckstr.o cktime.o ckuid.o ckyorn.o         \
		closefrom.o data.o devattr.o devreserv.o devtab.o dgrpent.o  \
		fulldevnm.o getdev.o getdgrp.o getinput.o getopt.o getpass.o \
		getvol.o listdev.o listdgrp.o mkdirp.o pkginfo.o pkgnmchk.o  \
		pkgparam.o putdev.o putdgrp.o puterror.o puthelp.o           \
		putprmpt.o puttext.o rdwr_vtoc.o regexp.o sigsend.o space.o  \
		strlcat.o strlcpy.o
