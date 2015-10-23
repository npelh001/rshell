CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic

all: rshell

rshell:
	$(CC) $(CFLAGS) src/*.cpp -o bin/rshell
