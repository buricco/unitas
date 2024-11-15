CC ?= cc

spline:	spline.o
	$(CC) $(LDFLAGS) -o spline spline.o

spline.o:	spline.c
	$(CC) $(CFLAGS) -c -o spline.o spline.c

clean:
	rm -f spline spline.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin spline
