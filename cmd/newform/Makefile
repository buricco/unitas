all:	newform

newform:	newform.o

newform.o:	newform.c

clean:
	rm -f newform newform.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin newform
