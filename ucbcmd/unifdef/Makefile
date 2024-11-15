CC ?= cc

unifdef:	unifdef.o
	$(CC) $(LDFLAGS) -o unifdef unifdef.o

unifdef.o:	unifdef.c
	$(CC) $(CFLAGS) -c -o unifdef.o unifdef.c

clean:
	rm -f unifdef unifdef.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb unifdef
