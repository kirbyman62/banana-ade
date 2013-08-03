# Yeah I have no clue what I'm doing here.
CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-Wall -c

SDIR=.
ODIR=$(SDIR)obj/

$(ODIR)character.o: $(SDIR)character.cpp $(SDIR)character.h
	$(CC) $(FLAGS) $(SDIR)character.cpp
	mv character.o $(ODIR)

$(ODIR)playableCharacter.o: $(SDIR)playableCharacter.cpp $(SDIR)playableCharacter.h
	$(CC) $(FLAGS) $(SDIR)playableCharacter.cpp
	mv playableCharacter.o $(ODIR)

$(ODIR)level.o: $(SDIR)level.cpp $(SDIR)level.h
	$(CC) $(FLAGS) $(SDIR)level.cpp
	mv playableCharacter.o $(ODIR)

.PHONY: clean
clean:
	rm $(ODIR)*.o
