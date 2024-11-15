all:	talk

talk:	ctl.o ctl_transact.o display.o get_addrs.o get_names.o init_disp.o invite.o io.o look_up.o msgs.o talk.o
	$(CC) $(LDFLAGS) -o talk ctl.o ctl_transact.o display.o get_addrs.o get_names.o init_disp.o invite.o io.o look_up.o msgs.o talk.o -lcurses -lsocket -lucb -lnsl

ctl.o:	ctl.c talk_ctl.h ctl.h talk.h
	$(CC) $(CFLAGS) -c -o ctl.o ctl.c

ctl_transact.o:	ctl_transact.c talk_ctl.h ctl.h talk.h
	$(CC) $(CFLAGS) -c -o ctl_transact.o ctl_transact.c

display.o:	display.c talk.h
	$(CC) $(CFLAGS) -c -o display.o display.c

get_addrs.o:	get_addrs.c talk_ctl.h ctl.h talk.h
	$(CC) $(CFLAGS) -c -o get_addrs.o get_addrs.c

get_names.o:	get_names.c talk.h ctl.h
	$(CC) $(CFLAGS) -c -o get_names.o get_names.c

init_disp.o:	init_disp.c talk.h
	$(CC) $(CFLAGS) -c -o init_disp.o init_disp.c

invite.o:	invite.c talk_ctl.h ctl.h talk.h
	$(CC) $(CFLAGS) -c -o invite.o invite.c

io.o:	io.c talk.h
	$(CC) $(CFLAGS) -c -o io.o io.c

look_up.o:	look_up.c talk_ctl.h ctl.h talk.h
	$(CC) $(CFLAGS) -c -o look_up.o look_up.c

msgs.o:	msgs.c talk.h
	$(CC) $(CFLAGS) -c -o msgs.o msgs.c

talk.o:	talk.c talk.h
	$(CC) $(CFLAGS) -c -o talk.o talk.c

clean:
	rm -f talk ctl.o ctl_transact.o display.o get_addrs.o get_names.o init_disp.o invite.o io.o look_up.o msgs.o talk.o
