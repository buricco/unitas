mvdir:	mvdir.sh
	cp mvdir.sh mvdir

clean:
	rm -f mvdir

install:
	sh ../install/sysinstall.sh $(ROOT)/usr/sbin mvdir
	ln -s ../usr/sbin/mvdir $(ROOT)/etc/mvdir
