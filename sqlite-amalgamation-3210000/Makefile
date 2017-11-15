
all:
	gcc -o libxmsqlite3.so -shared -fPIC sqlite3.c sqlite3ext.h  sqlite3.h
	gcc -o sqlite3  shell.c sqlite3.h  -L./ -I./  -lxmsqlite3 -lpthread -ldl

clean:
	rm -rf libsqlite3.so  libxmsqlite3.so sqlite3