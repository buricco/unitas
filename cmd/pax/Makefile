pax:	pax.o append.o buffer.o paxcpio.o create.o extract.o fileio.o link.o \
	list.o mem.o namelist.o names.o pass.o pathname.o port.o regexp.o    \
	replace.o ustar.o ttyio.o warn.o wildmat.o
	$(CC) $(LDFLAGS) -o pax pax.o append.o buffer.o paxcpio.o create.o   \
		extract.o fileio.o link.o list.o mem.o namelist.o names.o    \
		pass.o pathname.o port.o regexp.o replace.o ustar.o ttyio.o  \
		warn.o wildmat.o

pax.o:	pax.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o pax.o pax.c

append.o:	append.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o append.o append.c

buffer.o:	buffer.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o buffer.o buffer.c

paxcpio.o:	paxcpio.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o paxcpio.o paxcpio.c

create.o:	create.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o create.o create.c

extract.o:	extract.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o extract.o extract.c

fileio.o:	fileio.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o fileio.o fileio.c

link.o:	link.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o link.o link.c

list.o:	list.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o list.o list.c

mem.o:	mem.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o mem.o mem.c

namelist.o:	namelist.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o namelist.o namelist.c

names.o:	names.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o names.o names.c

pass.o:	pass.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o pass.o pass.c

pathname.o:	pathname.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o pathname.o pathname.c

port.o:	port.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o port.o port.c

regexp.o:	regexp.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o regexp.o regexp.c

replace.o:	replace.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o replace.o replace.c

ustar.o:	ustar.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o ustar.o ustar.c

ttyio.o:	ttyio.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o ttyio.o ttyio.c

warn.o:	warn.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o warn.o warn.c

wildmat.o:	wildmat.c pax.h config.h limits.h regexp.h port.h func.h
	$(CC) $(CFLAGS) -c -o wildmat.o wildmat.c

clean:
	rm -f pax pax.o append.o buffer.o paxcpio.o create.o extract.o       \
		fileio.o link.o list.o mem.o namelist.o names.o pass.o       \
		pathname.o port.o regexp.o replace.o ustar.o ttyio.o warn.o  \
		wildmat.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin pax
	ln -fs ../usr/bin/pax $(ROOT)/sbin/tar
	ln -fs pax $(ROOT)/usr/bin/tar
	ln -fs ../bin/pax $(ROOT)/usr/sbin/tar
	ln -fs pax $(ROOT)/usr/bin/cpio
