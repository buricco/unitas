all:	copy

copy:	copy.o sfile.o memalign.o
	$(CC) -o copy copy.o sfile.o memalign.o $(LDFLAGS)

copy.o: copy.c sfile.h memalign.h
	$(CC) $(CFLAGS) -c -o copy.o copy.c

sfile.o: sfile.c sfile.h
	$(CC) $(CFLAGS) -c -o sfile.o sfile.c

memalign.o:	memalign.c memalign.h
	$(CC) $(CFLAGS) -c -o memalign.o memalign.c

clean:
	rm -f copy copy.o sfile.o memalign.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin copy
