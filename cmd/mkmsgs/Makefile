all:	mkmsgs

mkmsgs:	mkmsgs.o strccpy.o
	$(CC) -o mkmsgs mkmsgs.o strccpy.o

mkmsgs.o:
	$(CC) -c -o mkmsgs.o mkmsgs.c

strccpy.o:
	$(CC) -c -o strccpy.o strccpy.c

clean:
	rm -f mkmsgs mkmsgs.o strccpy.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin mkmsgs
