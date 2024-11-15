all:	addbib hunt indxbib inv lookbib mkey refer roffbib sortbib

indxbib:	indxbib.sh
	cp indxbib.sh indxbib

roffbib:	roffbib.sh
	cp roffbib.sh roffbib

addbib:	addbib.o
	$(CC) $(LDFLAGS) -o addbib addbib.o

lookbib:	lookbib.o
	$(CC) $(LDFLAGS) -o lookbib lookbib.o

sortbib:	sortbib.o
	$(CC) $(LDFLAGS) -o sortbib sortbib.o

mkey:	mkey1.o mkey2.o mkey3.o deliv2.o
	$(CC) $(LDFLAGS) -o mkey mkey1.o mkey2.o mkey3.o deliv2.o

inv:	inv1.o inv2.o inv3.o inv5.o inv6.o deliv2.o
	$(CC) $(LDFLAGS) -o inv inv1.o inv2.o inv3.o inv5.o inv6.o deliv2.o

hunt:	hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o refer3.o glue4.o glue5.o shell.o deliv2.o tick.o
	$(CC) $(LDFLAGS) -o hunt hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o refer3.o glue4.o glue5.o shell.o deliv2.o tick.o

refer:	glue1.o glue2.o glue3.o glue4.o glue5.o refer0.o refer1.o refer2.o refer4.o refer5.o refer6.o refer7.o refer8.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o mkey3.o shell.o deliv2.o
	$(CC) $(LDFLAGS) -o refer glue1.o glue2.o glue3.o glue4.o glue5.o refer0.o refer1.o refer2.o refer4.o refer5.o refer6.o refer7.o refer8.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o mkey3.o shell.o deliv2.o

addbib.o:	addbib.c
	$(CC) $(CFLAGS) -c -o addbib.o addbib.c

deliv2.o:	deliv2.c
	$(CC) $(CFLAGS) -c -o deliv2.o deliv2.c

glue1.o:	glue1.c
	$(CC) $(CFLAGS) -c -o glue1.o glue1.c

glue2.o:	glue2.c pathnames.h
	$(CC) $(CFLAGS) -c -o glue2.o glue2.c

glue3.o:	glue3.c refer..c pathnames.h
	$(CC) $(CFLAGS) -c -o glue3.o glue3.c

glue4.o:	glue4.c pathnames.h
	$(CC) $(CFLAGS) -c -o glue4.o glue4.c

glue5.o:	glue5.c
	$(CC) $(CFLAGS) -c -o glue5.o glue5.c

hunt1.o:	hunt1.c
	$(CC) $(CFLAGS) -c -o hunt1.o hunt1.c

hunt2.o:	hunt2.c refer..c
	$(CC) $(CFLAGS) -c -o hunt2.o hunt2.c

hunt3.o:	hunt3.c refer..c
	$(CC) $(CFLAGS) -c -o hunt3.o hunt3.c

hunt5.o:	hunt5.c
	$(CC) $(CFLAGS) -c -o hunt5.o hunt5.c

hunt6.o:	hunt6.c
	$(CC) $(CFLAGS) -c -o hunt6.o hunt6.c

hunt7.o:	hunt7.c
	$(CC) $(CFLAGS) -c -o hunt7.o hunt7.c

hunt8.o:	hunt8.c pathnames.h
	$(CC) $(CFLAGS) -c -o hunt8.o hunt8.c

hunt9.o:	hunt9.c
	$(CC) $(CFLAGS) -c -o hunt9.o hunt9.c

inv1.o:	inv1.c pathnames.h
	$(CC) $(CFLAGS) -c -o inv1.o inv1.c

inv2.o:	inv2.c
	$(CC) $(CFLAGS) -c -o inv2.o inv2.c

inv3.o:	inv3.c
	$(CC) $(CFLAGS) -c -o inv3.o inv3.c

inv5.o:	inv5.c
	$(CC) $(CFLAGS) -c -o inv5.o inv5.c

inv6.o:	inv6.c
	$(CC) $(CFLAGS) -c -o inv6.o inv6.c

lookbib.o:	lookbib.c pathnames.h
	$(CC) $(CFLAGS) -c -o lookbib.o lookbib.c

mkey1.o:	mkey1.c
	$(CC) $(CFLAGS) -c -o mkey1.o mkey1.c

mkey2.o:	mkey2.c
	$(CC) $(CFLAGS) -c -o mkey2.o mkey2.c

mkey3.o:	mkey3.c pathnames.h
	$(CC) $(CFLAGS) -c -o mkey3.o mkey3.c

refer0.o:	refer0.c refer..c
	$(CC) $(CFLAGS) -c -o refer0.o refer0.c

refer1.o:	refer1.c refer..c pathnames.h
	$(CC) $(CFLAGS) -c -o refer1.o refer1.c

refer2.o:	refer2.c refer..c
	$(CC) $(CFLAGS) -c -o refer2.o refer2.c

refer3.o:	refer3.c refer..c
	$(CC) $(CFLAGS) -c -o refer3.o refer3.c

refer4.o:	refer4.c refer..c
	$(CC) $(CFLAGS) -c -o refer4.o refer4.c

refer5.o:	refer5.c refer..c pathnames.h
	$(CC) $(CFLAGS) -c -o refer5.o refer5.c

refer6.o:	refer6.c refer..c
	$(CC) $(CFLAGS) -c -o refer6.o refer6.c

refer7.o:	refer7.c refer..c
	$(CC) $(CFLAGS) -c -o refer7.o refer7.c

refer8.o:	refer8.c refer..c
	$(CC) $(CFLAGS) -c -o refer8.o refer8.c

shell.o:	shell.c
	$(CC) $(CFLAGS) -c -o shell.o shell.c

sortbib.o:	sortbib.c pathnames.h
	$(CC) $(CFLAGS) -c -o sortbib.o sortbib.c

tick.o:	tick.c
	$(CC) $(CFLAGS) -c -o tick.o tick.c

clean:
	rm -f addbib hunt indxbib inv lookbib mkey refer roffbib sortbib addbib.o deliv2.o glue1.o glue2.o glue3.o glue4.o glue5.o hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o inv1.o inv2.o inv3.o inv5.o inv6.o lookbib.o mkey1.o mkey2.o mkey3.o refer0.o refer1.o refer2.o refer3.o refer4.o refer5.o refer6.o refer7.o refer8.o shell.o sortbib.o tick.o
