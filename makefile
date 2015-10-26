CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic
SDIR=src
ODIR=bin

all: rshell

rshell:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(SDIR)/*.cpp $(SDIR)/*.h -o $(ODIR)/rshell
