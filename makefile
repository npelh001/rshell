CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic
SDIR=src
ODIR=build
BDIR=bin

all: rshell

rshell: $(ODIR)main.o $(ODIR)instruction.o $(ODIR)command.o $(ODIR)connector.o $(ODIR)parser.o
	mkdir -p $(BDIR)
	$(CC) $(CFLAGS) $(ODIR)/*.o -o $(BDIR)/rshell

$(ODIR)main.o:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $(SDIR)/main.cpp -o $(ODIR)/main.o

$(ODIR)instruction.o:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $(SDIR)/instruction.cpp -o $(ODIR)/instruction.o

$(ODIR)command.o:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $(SDIR)/command.cpp -o $(ODIR)/command.o

$(ODIR)connector.o:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $(SDIR)/connector.cpp -o $(ODIR)/connector.o

$(ODIR)parser.o:
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $(SDIR)/parser.cpp -o $(ODIR)/parser.o

clean:
	rm -r $(BDIR) $(ODIR)
