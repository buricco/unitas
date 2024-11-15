CC ?= cc

logger:	logger.o
	$(CC) $(LDFLAGS) -o logger logger.o

logger.o:	logger.c
	$(CC) $(CFLAGS) -c -o logger.o logger.c

clean:
	rm -f logger logger.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb logger
