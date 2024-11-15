tftp:	main.o tftp.o tftpsubs.o
	$(CC) $(LDFLAGS) -o tftp main.o tftp.o tftpsubs.o

main.o:	main.c extern.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o main.o main.c

tftp.o:	tftp.c extern.h tftpsubs.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o tftp.o tftp.c

tftpsubs.o:	tftpsubs.c tftpsubs.h
	$(CC) $(CFLAGS) -DSYSV -DSTRNET -BSD_COMP -c -o tftpsubs.o tftpsubs.c

clean:
	rm -f tftp main.o tftp.o tftpsubs.o

install:
	sh ../../../install/sysinstall.sh $(ROOT)/usr/bin tftp
