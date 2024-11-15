all:	ping in.comsat in.fingerd in.rshd in.tftpd in.tnamed htable in.talkd

htable:
	make -C htable

in.talkd:
	make -C in.talkd

ping:	ping.o 
	$(CC) $(LDFLAGS) -o ping ping.o -lsocket -lnsl 

in.comsat:	in.comsat.o 
	$(CC) $(LDFLAGS) -o in.comsat in.comsat.o -lsocket -lnsl 

in.fingerd:	in.fingerd.o 
	$(CC) $(LDFLAGS) -o in.fingerd in.fingerd.o -lsocket -lnsl 

in.rshd:	in.rshd.o 
	$(CC) $(LDFLAGS) -o in.rshd in.rshd.o -lsocket -lnsl -lucb

in.tftpd:	in.tftpd.o tftpsubs.o 
	$(CC) $(LDFLAGS) -o in.tftpd in.tftpd.o tftpsubs.o -lsocket -lnsl 

in.tnamed:	in.tnamed.o 
	$(CC) $(LDFLAGS) -o in.tnamed in.tnamed.o -lsocket -lnsl 

ping.o:	ping.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -c -o ping.o ping.c

in.comsat.o:	in.comsat.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -c -o in.comsat.o in.comsat.c

in.fingerd.o:	in.fingerd.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -c -o in.fingerd.o in.fingerd.c

in.rshd.o:	in.rshd.c
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -c -o in.rshd.o in.rshd.c

in.tftpd.o:	in.tftpd.c ../usr.bin/tftp/tftpsubs.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -I../usr.bin/tftp -c -o in.tftpd.o in.tftpd.c

tftpsubs.o:	../usr.bin/tftp/tftpsubs.c ../usr.bin/tftp/tftpsubs.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -DDEBUG -I../usr.bin/tftp -c -o tftpsubs.o ../usr.bin/tftp/tftpsubs.c

clean:
	rm -f ping in.comsat in.fingerd in.rshd in.tftpd in.tnamed in.comsat.o in.fingerd.o in.rshd.o in.tftpd.o in.tnamed.o tftpsubs.o
	make -C htable clean
	make -C in.talkd clean

install:
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin ping
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin in.comsat
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin in.fingerd
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin in.rshd
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin in.tftpd
	sh ../../install/sysinstall.sh $(ROOT)/usr/sbin in.tnamed
	make -C htable install
	make -C in.talkd install
