all: uniq

uniq:	uniq.o
	$(CC) -o uniq uniq.o

uniq.o:	
	$(CC) -o uniq.o -c uniq.c

clean:
	rm -f uniq uniq.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin uniq
