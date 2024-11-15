all:	banner

banner:	banner.o
	$(CC) $(LDFLAGS) -o banner banner.o

banner.o:	banner.c
	$(CC) $(CFLAGS) -c -o banner.o banner.c

clean:
	rm -f banner banner.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin banner
