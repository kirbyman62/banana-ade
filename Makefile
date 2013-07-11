# Yeah I have no clue what I'm doing here.
CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-Wall -c

SDIR=src/
ODIR=$(SDIR)obj/

$(ODIR)character.o: $(SDIR)character.cpp $(SDIR)character.h
	$(CC) $(FLAGS) $(SDIR)character.cpp
	mv character.o $(ODIR)

.PHONY: clean
clean:
	rm $(ODIR)*.o
