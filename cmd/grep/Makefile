all:	grep

grep:	grep.o getline.o regcomp.o regerror.o regexec.o regfree.o
	$(CC) $(LDFLAGS)  -o grep grep.o getline.o regcomp.o regerror.o regexec.o regfree.o

grep.o:	grep.c getline.h regex.h
	$(CC) $(CFLAGS) -c -o grep.o grep.c

getline.o:	getline.c getline.h
	$(CC) $(CFLAGS) -c -o getline.o getline.c

regcomp.o:	regcomp.c cclass.h cname.h regex2.h regex.h utils.h
	$(CC) $(CFLAGS) -c -o regcomp.o regcomp.c

regerror.o:	regerror.c regex.h utils.h
	$(CC) $(CFLAGS) -c -o regerror.o regerror.c

regexec.o:	regexec.c regex2.h utils.h engine.c
	$(CC) $(CFLAGS) -c -o regexec.o regexec.c

regfree.o:	regfree.c regex2.h regex.h utils.h
	$(CC) $(CFLAGS) -c -o regfree.o regfree.c

clean:
	rm -f grep grep.o getline.o regcomp.o regerror.o regexec.o regfree.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin grep
	sh ../install/sysinstall.sh $(ROOT)/sbin grep
	ln -fs ../sbin/grep $(ROOT)/usr/bin/grep
	ln -fs grep $(ROOT)/usr/bin/egrep
	ln -fs grep $(ROOT)/usr/bin/fgrep
