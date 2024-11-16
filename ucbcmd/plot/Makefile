all:	vplot crtplot plottoa atoplot plot aedplot bgplot dumbplot gigiplot  \
	hpplot hp7221plot implot t300 t300s t4013 tek t450 vt0

vplot:	vplot.o chrtab.o
	${CC} $(LDFLAGS) -o vplot vplot.o chrtab.o

crtplot:	crtplot.o crtdriver.o
	${CC} $(LDFLAGS) -o crtplot crtplot.o crtdriver.o -lcurses -lm

plottoa:	plottoa.o
	${CC} $(LDFLAGS) -o plottoa plottoa.o

plot:	plot.sh
	cp plot.sh plot

atoplot.o:	atoplot.c
	$(CC) $(CFLAGS) -c -o atoplot.o atoplot.c

chrtab.o:	chrtab.c
	$(CC) $(CFLAGS) -c -o chrtab.o chrtab.c

crtdriver.o:	crtdriver.c
	$(CC) $(CFLAGS) -c -o crtdriver.o crtdriver.c

crtplot.o:	crtplot.c
	$(CC) $(CFLAGS) -c -o crtplot.o crtplot.c

debug.o:	debug.c
	$(CC) $(CFLAGS) -c -o debug.o debug.c

driver.o:	driver.c
	$(CC) $(CFLAGS) -c -o driver.o driver.c

plottoa.o:	plottoa.c
	$(CC) $(CFLAGS) -c -o plottoa.o plottoa.c

vplot.o:	vplot.c vfont.h
	$(CC) $(CFLAGS) -c -o vplot.o vplot.c

aedplot:	libplot/libaed.a driver.o
	$(CC) $(LDFLAGS) -o aedplot driver.o -Llibplot -laed -lm

bgplot:	libplot/libbitgraph.a driver.o
	$(CC) $(LDFLAGS) -o bgplot driver.o -Llibplot -lbitgraph -lm

dumbplot:	libplot/libdumb.a driver.o
	$(CC) $(LDFLAGS) -o dumbplot driver.o -Llibplot -ldumb -lcurses -lm

gigiplot:	libplot/libgigi.a driver.o
	$(CC) $(LDFLAGS) -o gigiplot driver.o -Llibplot -lgigi -lm

hpplot:	libplot/libhp2648.a driver.o
	$(CC) $(LDFLAGS) -o hpplot driver.o -Llibplot -lhp2648 -lm

hp7221plot:	libplot/libhp7221.a driver.o
	$(CC) $(LDFLAGS) -o hp7221plot driver.o -Llibplot -lhp7221 -lm

implot:	libplot/libimagen.a driver.o
	$(CC) $(LDFLAGS) -o implot driver.o -Llibplot -limagen -lm

atoplot:	libplot/libplot.a atoplot.o
	$(CC) $(LDFLAGS) -o atoplot atoplot.o -Llibplot -lplot -lm

t300:	libplot/libt300.a driver.o
	$(CC) $(LDFLAGS) -o t300 driver.o -Llibplot -lt300 -lm

t300s:	libplot/libt300s.a driver.o
	$(CC) $(LDFLAGS) -o t300s driver.o -Llibplot -lt300s -lm

t4013:	libplot/libt4013.a driver.o
	$(CC) $(LDFLAGS) -o t4013 driver.o -Llibplot -lt4013 -lm

tek:	libplot/libt4014.a driver.o
	$(CC) $(LDFLAGS) -o tek driver.o -Llibplot -lt4014 -lm

t450:	libplot/libt450.a driver.o
	$(CC) $(LDFLAGS) -o t450 driver.o -Llibplot -lt450 -lm

vt0:	libplot/libvt0.a driver.o
	$(CC) $(LDFLAGS) -o vt0 driver.o -Llibplot -lvt0 -lm

libplot/libaed.a libplot/libbitgraph.a libplot/libdumb.a libplot/libgigi.a   \
	libplot/libhp2648.a libplot/libhp7221.a libplot/libimagen.a          \
	libplot/libplot.a libplot/libt300.a libplot/libt300s.a               \
	libplot/libt4013.a libplot/libt4014.a libplot/libt450.a              \
	libplot/libtf77.a libplot/libvt0.a:
	make -C libplot

clean:
	make -C libplot clean
	rm -f atoplot.o chrtab.o crtdriver.o crtplot.o debug.o driver.o      \
		plottoa.o vplot.o vplot crtplot plottoa atoplot plot aedplot \
		bgplot dumbplot gigiplot hpplot hp7221plot implot t300 t300s \
		t4013 tek t450 vt0
