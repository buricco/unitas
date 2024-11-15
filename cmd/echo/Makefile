all:	echo

echo:	echo.o
	$(CC) $(LDFLAGS) -o echo echo.o

echo.o:	echo.c
	$(CC) $(CFLAGS) -c -o echo.o echo.c

clean:
	rm -f echo echo.o

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/bin echo
