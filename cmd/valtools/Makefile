CC ?= cc

all:	ckdate ckgid ckint ckitem ckkeywd ckpath ckrange ckstr cktime ckuid  \
	ckyorn puttext

ckdate:	ckdate.o
	$(CC) $(LDFLAGS) -o ckdate ckdate.o -ladm

ckgid:	ckgid.o
	$(CC) $(LDFLAGS) -o ckgid ckgid.o -ladm

ckint:	ckint.o
	$(CC) $(LDFLAGS) -o ckint ckint.o -ladm

ckitem:	ckitem.o
	$(CC) $(LDFLAGS) -o ckitem ckitem.o -ladm

ckkeywd:	ckkeywd.o
	$(CC) $(LDFLAGS) -o ckkeywd ckkeywd.o -ladm

ckpath:	ckpath.o
	$(CC) $(LDFLAGS) -o ckpath ckpath.o -ladm

ckrange:	ckrange.o
	$(CC) $(LDFLAGS) -o ckrange ckrange.o -ladm

ckstr:	ckstr.o
	$(CC) $(LDFLAGS) -o ckstr ckstr.o -ladm

cktime:	cktime.o
	$(CC) $(LDFLAGS) -o cktime cktime.o -ladm

ckuid:	ckuid.o
	$(CC) $(LDFLAGS) -o ckuid ckuid.o -ladm

ckyorn:	ckyorn.o
	$(CC) $(LDFLAGS) -o ckyorn ckyorn.o -ladm

puttext:	puttext.o
	$(CC) $(LDFLAGS) -o puttext puttext.o -ladm

ckdate.o:	ckdate.c usage.h
	$(CC) $(CFLAGS) -c -o ckdate.o ckdate.c

ckgid.o:	ckgid.c usage.h
	$(CC) $(CFLAGS) -c -o ckgid.o ckgid.c

ckint.o:	ckint.c usage.h
	$(CC) $(CFLAGS) -c -o ckint.o ckint.c

ckitem.o:	ckitem.c usage.h valtools.h
	$(CC) $(CFLAGS) -c -o ckitem.o ckitem.c

ckkeywd.o:	ckkeywd.c usage.h
	$(CC) $(CFLAGS) -c -o ckkeywd.o ckkeywd.c

ckpath.o:	ckpath.c usage.h valtools.h
	$(CC) $(CFLAGS) -c -o ckpath.o ckpath.c

ckrange.o:	ckrange.c usage.h
	$(CC) $(CFLAGS) -c -o ckrange.o ckrange.c

ckstr.o:	ckstr.c usage.h
	$(CC) $(CFLAGS) -c -o ckstr.o ckstr.c

cktime.o:	cktime.c usage.h
	$(CC) $(CFLAGS) -c -o cktime.o cktime.c

ckuid.o:	ckuid.c usage.h
	$(CC) $(CFLAGS) -c -o ckuid.o ckuid.c

ckyorn.o:	ckyorn.c usage.h
	$(CC) $(CFLAGS) -c -o ckyorn.o ckyorn.c

puttext.o:	puttext.c
	$(CC) $(CFLAGS) -c -o puttext.o puttext.c

clean:
	rm -f ckdate ckgid ckint ckitem ckkeywd ckpath ckrange ckstr cktime  \
	ckuid ckyorn puttext ckdate.o ckgid.o ckint.o ckitem.o ckkeywd.o     \
	ckpath.o ckrange.o ckstr.o cktime.o ckuid.o ckyorn.o puttext.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sadm/bin puttext
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckdate
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckgid
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckint
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckitem
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckkeywd
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckpath
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckrange
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckstr
	sh ../install/sysinstall.sh $(ROOT)/usr/bin cktime
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckuid
	sh ../install/sysinstall.sh $(ROOT)/usr/bin ckyorn
	ln -fs ../../bin/ckdate $(ROOT)/usr/sadm/bin/valdate
	ln -fs ../../bin/ckdate $(ROOT)/usr/sadm/bin/helpdate
	ln -fs ../../bin/ckdate $(ROOT)/usr/sadm/bin/errdate
	ln -fs ../../bin/ckgid $(ROOT)/usr/sadm/bin/valgid
	ln -fs ../../bin/ckgid $(ROOT)/usr/sadm/bin/helpgid
	ln -fs ../../bin/ckgid $(ROOT)/usr/sadm/bin/errgid
	ln -fs ../../bin/ckint $(ROOT)/usr/sadm/bin/valint
	ln -fs ../../bin/ckint $(ROOT)/usr/sadm/bin/helpint
	ln -fs ../../bin/ckint $(ROOT)/usr/sadm/bin/errint
	ln -fs ../../bin/ckitem $(ROOT)/usr/sadm/bin/valitem
	ln -fs ../../bin/ckitem $(ROOT)/usr/sadm/bin/helpitem
	ln -fs ../../bin/ckitem $(ROOT)/usr/sadm/bin/erritem
	ln -fs ../../bin/ckkeywd $(ROOT)/usr/sadm/bin/valkeywd
	ln -fs ../../bin/ckkeywd $(ROOT)/usr/sadm/bin/helpkeywd
	ln -fs ../../bin/ckkeywd $(ROOT)/usr/sadm/bin/errkeywd
	ln -fs ../../bin/ckpath $(ROOT)/usr/sadm/bin/valpath
	ln -fs ../../bin/ckpath $(ROOT)/usr/sadm/bin/helppath
	ln -fs ../../bin/ckpath $(ROOT)/usr/sadm/bin/errpath
	ln -fs ../../bin/ckrange $(ROOT)/usr/sadm/bin/valrange
	ln -fs ../../bin/ckrange $(ROOT)/usr/sadm/bin/helprange
	ln -fs ../../bin/ckrange $(ROOT)/usr/sadm/bin/errrange
	ln -fs ../../bin/ckstr $(ROOT)/usr/sadm/bin/valstr
	ln -fs ../../bin/ckstr $(ROOT)/usr/sadm/bin/helpstr
	ln -fs ../../bin/ckstr $(ROOT)/usr/sadm/bin/errstr
	ln -fs ../../bin/cktime $(ROOT)/usr/sadm/bin/valtime
	ln -fs ../../bin/cktime $(ROOT)/usr/sadm/bin/helptime
	ln -fs ../../bin/cktime $(ROOT)/usr/sadm/bin/errtime
	ln -fs ../../bin/ckuid $(ROOT)/usr/sadm/bin/valuid
	ln -fs ../../bin/ckuid $(ROOT)/usr/sadm/bin/helpuid
	ln -fs ../../bin/ckuid $(ROOT)/usr/sadm/bin/erruid
	ln -fs ../../bin/ckyorn $(ROOT)/usr/sadm/bin/valyorn
	ln -fs ../../bin/ckyorn $(ROOT)/usr/sadm/bin/helpyorn
	ln -fs ../../bin/ckyorn $(ROOT)/usr/sadm/bin/erryorn
