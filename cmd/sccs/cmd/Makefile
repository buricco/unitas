all:	admin rmchg comb delta get prs unget val vc what help rmdel sact cdc

../lib/cassi.a:
	make -I../hdr -c ../lib/cassi

../lib/comobj.a:
	make -I../hdr -c ../lib/comobj

../lib/mpwlib.a:
	make -I../hdr -c ../lib/mpwlib

cdc:	rmchg
	ln -fs rmchg cdc

rmdel:	rmchg
	ln -fs rmchg rmdel

sact:	unget
	ln -fs unget sact

admin:	admin.o
	$(CC) $(LDFLAGS) -o admin admin.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

rmchg:	rmchg.o
	$(CC) $(LDFLAGS) -o rmchg rmchg.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

comb:	comb.o
	$(CC) $(LDFLAGS) -o comb comb.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

delta:	delta.o
	$(CC) $(LDFLAGS) -o delta delta.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

get:	get.o
	$(CC) $(LDFLAGS) -o get get.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

prs:	prs.o
	$(CC) $(LDFLAGS) -o prs prs.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

unget:	unget.o
	$(CC) $(LDFLAGS) -o unget unget.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

val:	val.o
	$(CC) $(LDFLAGS) -o val val.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

vc:	vc.o
	$(CC) $(LDFLAGS) -o vc vc.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

what:	what.o
	$(CC) $(LDFLAGS) -o what what.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

help:	help.o
	$(CC) $(LDFLAGS) -o help help.o ../lib/cassi.a ../lib/comobj.a ../lib/mpwlib.a

admin.o:	admin.c ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o admin.o admin.c

rmchg.o:	rmchg.c ../hdr/defines.h ../hdr/filehand.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o rmchg.o rmchg.c

comb.o:	comb.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o comb.o comb.c

delta.o:	delta.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o delta.o delta.c

get.o:	get.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o get.o get.c

prs.o:	prs.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o prs.o prs.c

unget.o:	unget.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o unget.o unget.c

val.o:	val.c ../hdr/defines.h ../hdr/had.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o val.o val.c

vc.o:	vc.c ../hdr/defines.h
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o vc.o vc.c

what.o:	what.c
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o what.o what.c

help.o:	help.c
	$(CC) $(CFLAGS) -I../../sgs/inc/common -I../../sgs/inc/common -I../hdr -c -o help.o help.c

clean:
	rm -f rmchg rmdel cdc sact admin rmchg comb delta get prs unget val vc what help sccsdiff admin.o rmchg.o comb.o delta.o get.o prs.o unget.o val.o vc.o what.o help.o

install:
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin admin
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin comb
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin delta
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin get
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin help
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin prs
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin rmchg
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin unget
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin val
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin vc
	sh ../../install/sysinstall.sh $(ROOT)/usr/ccs/bin what
	ln -fs ../ccs/bin/admin $(ROOT)/usr/bin/admin
	ln -fs ../ccs/bin/comb $(ROOT)/usr/bin/comb
	ln -fs ../ccs/bin/delta $(ROOT)/usr/bin/delta
	ln -fs ../ccs/bin/get $(ROOT)/usr/bin/get
	ln -fs ../ccs/bin/help $(ROOT)/usr/bin/help
	ln -fs ../ccs/bin/prs $(ROOT)/usr/bin/prs
	ln -fs ../ccs/bin/rmchg $(ROOT)/usr/bin/rmchg
	ln -fs ../ccs/bin/unget $(ROOT)/usr/bin/unget
	ln -fs ../ccs/bin/val $(ROOT)/usr/bin/val
	ln -fs ../ccs/bin/vc $(ROOT)/usr/bin/vc
	ln -fs ../ccs/bin/what $(ROOT)/usr/bin/what
	ln -fs ../ccs/bin/rmchg $(ROOT)/usr/bin/cdc
	ln -fs ../ccs/bin/rmchg $(ROOT)/usr/bin/rmdel
	ln -fs ../ccs/bin/unget $(ROOT)/usr/bin/sact
	ln -fs rmchg $(ROOT)/usr/ccs/bin/cdc
	ln -fs rmchg $(ROOT)/usr/ccs/bin/rmdel
	ln -fs unget $(ROOT)/usr/ccs/bin/sact
