CC ?= cc

news:	news.o
	$(CC) $(LDFLAGS) -o news news.o

news.o:	news.c
	$(CC) $(CFLAGS) -c -o news.o news.c

clean:
	rm -f news news.o


install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin news
