CC = gcc
CFLAGS = -O3 -Wall
OS = $(shell uname)

all:
	mkdir -p bin
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) -o bin/rot13 rot-tools/rot13.c
	$(CC) $(CFLAGS) -o bin/rot18 rot-tools/rot18.c
	$(CC) $(CFLAGS) -o bin/ascii2char ascii-tools/ascii2char.c
	$(CC) $(CFLAGS) -o bin/char2ascii ascii-tools/char2ascii.c
endif
ifeq ($(OS), Linux)
	$(CC) $(CFLAGS) -o bin/rot13 rot-tools/rot13.c
	$(CC) $(CFLAGS) -o bin/rot18 rot-tools/rot18.c
	$(CC) $(CFLAGS) -o bin/ascii2char ascii-tools/ascii2char.c
	$(CC) $(CFLAGS) -o bin/char2ascii ascii-tools/char2ascii.c
endif
ifeq ($(OS), CYGWIN_NT-5.1)
	$(CC) $(CFLAGS) -o bin/rot13 rot-tools/rot13.c
	$(CC) $(CFLAGS) -o bin/rot18 rot-tools/rot18.c
	$(CC) $(CFLAGS) -o bin/ascii2char ascii-tools/ascii2char.c
	$(CC) $(CFLAGS) -o bin/char2ascii ascii-tools/char2ascii.c
endif
install:
	cp bin/rot13 /usr/local/bin/rot13
	cp bin/rot18 /usr/local/bin/rot18
	cp bin/ascii2char /usr/local/bin/ascii2char
	cp bin/char2ascii /usr/local/bin/char2ascii
clean:
	rm -f ascii-tools/*.o
	rm -f rot-tools/*.o
	rm -r bin/
uninstall:
	rm -f /usr/local/bin/rot13
	rm -f /usr/local/bin/rot18
	rm -f /usr/local/bin/ascii2char
	rm -f /usr/local/bin/char2ascii