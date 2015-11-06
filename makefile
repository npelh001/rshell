CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic
SDIR=src
BDIR=build
ODIR=bin

all: rshell

rshell: main.o command.o connector.o parser.o
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(BDIR)/*.o -o $(ODIR)/rshell

main.o:
	mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -c $(SDIR)/main.cpp -o $(BDIR)/main.o

command.o:
	mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -c $(SDIR)/command.cpp -o $(BDIR)/command.o

connector.o:
	mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -c $(SDIR)/connector.cpp -o $(BDIR)/connector.o

parser.o:
	mkdir -p $(BDIR)
	$(CC) $(CFLAGS) -c $(SDIR)/parser.cpp -o $(BDIR)/parser.o

clean:
	rm -r $(BDIR) $(ODIR)
