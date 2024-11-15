all:	rsh finger ruptime rwho talk tftp whois

finger:
	make -C finger

rsh:
	make -C rsh

talk:
	make -C talk

tftp:
	make -C tftp

ruptime:	ruptime.o
	$(CC) $(LDFLAGS) -o ruptime ruptime.o

rwho:	rwho.o
	$(CC) $(LDFLAGS) -o rwho rwho.o

whois:	whois.o
	$(CC) $(LDFLAGS) -o whois whois.o

rcp.o:	rcp.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o rcp.o rcp.c

rlogin.o:	rlogin.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o rlogin.o rlogin.c

rdate.o:	rdate.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o rdate.o rdate.c

ruptime.o:	ruptime.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o ruptime.o ruptime.c

rwho.o:	rwho.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o rwho.o rwho.c

telnet.o:	telnet.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o telnet.o telnet.c

whois.o:	whois.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o whois.o whois.c

clean:
	rm -f ruptime rwho whois ruptime.o rwho.o whois.o
	make -C finger clean
	make -C rsh clean
	make -C talk clean
	make -C tftp clean

install:
	sh ../../install/sysinstall.sh $(ROOT)/usr/bin ruptime
	sh ../../install/sysinstall.sh $(ROOT)/usr/bin rwho
	sh ../../install/sysinstall.sh $(ROOT)/usr/bin whois
	make -C finger install
	make -C rsh install
	make -C talk install
	make -C tftp install
