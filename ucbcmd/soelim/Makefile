CC ?= cc

soelim:	soelim.o
	$(CC) $(LDFLAGS) -o soelim soelim.o

soelim.o:	soelim.c
	$(CC) $(CFLAGS) -c -o soelim.o soelim.c

clean:
	rm -f soelim soelim.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb soelim
