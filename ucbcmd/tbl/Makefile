tbl:	t0.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o tb.o tc.o te.o tf.o tg.o ti.o tm.o ts.o tt.o tu.o tv.o
	$(CC) $(LDFLAGS) -o tbl t0.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o tb.o tc.o te.o tf.o tg.o ti.o tm.o ts.o tt.o tu.o tv.o

t0.o:	t0.c t..c
	$(CC) $(CFLAGS) -c -o t0.o t0.c

t1.o:	t1.c t..c pathnames.h
	$(CC) $(CFLAGS) -c -o t1.o t1.c

t2.o:	t2.c t..c
	$(CC) $(CFLAGS) -c -o t2.o t2.c

t3.o:	t3.c t..c
	$(CC) $(CFLAGS) -c -o t3.o t3.c

t4.o:	t4.c t..c
	$(CC) $(CFLAGS) -c -o t4.o t4.c

t5.o:	t5.c t..c
	$(CC) $(CFLAGS) -c -o t5.o t5.c

t6.o:	t6.c t..c
	$(CC) $(CFLAGS) -c -o t6.o t6.c

t7.o:	t7.c t..c
	$(CC) $(CFLAGS) -c -o t7.o t7.c

t8.o:	t8.c t..c
	$(CC) $(CFLAGS) -c -o t8.o t8.c

t9.o:	t9.c t..c
	$(CC) $(CFLAGS) -c -o t9.o t9.c

tb.o:	tb.c t..c
	$(CC) $(CFLAGS) -c -o tb.o tb.c

tc.o:	tc.c t..c
	$(CC) $(CFLAGS) -c -o tc.o tc.c

te.o:	te.c t..c
	$(CC) $(CFLAGS) -c -o te.o te.c

tf.o:	tf.c t..c
	$(CC) $(CFLAGS) -c -o tf.o tf.c

tg.o:	tg.c t..c
	$(CC) $(CFLAGS) -c -o tg.o tg.c

ti.o:	ti.c t..c
	$(CC) $(CFLAGS) -c -o ti.o ti.c

tm.o:	tm.c t..c
	$(CC) $(CFLAGS) -c -o tm.o tm.c

ts.o:	ts.c
	$(CC) $(CFLAGS) -c -o ts.o ts.c

tt.o:	tt.c t..c
	$(CC) $(CFLAGS) -c -o tt.o tt.c

tu.o:	tu.c t..c
	$(CC) $(CFLAGS) -c -o tu.o tu.c

tv.o:	tv.c t..c
	$(CC) $(CFLAGS) -c -o tv.o tv.c

clean:
	rm -f tbl t0.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o tb.o tc.o te.o tf.o tg.o ti.o tm.o ts.o tt.o tu.o tv.o

install:
	sh ../../cmd/install/sysinstall.sh $(ROOT)/usr/ucb tbl
