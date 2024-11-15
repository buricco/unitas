CC ?= cc

write:	write.o
	$(CC) $(LDFLAGS) -o write write.o

write.o:	write.c
	$(CC) $(CFLAGS) -c -o write.o write.c

clean:
	rm -f write write.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin write
