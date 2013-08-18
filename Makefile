# Yeah I have no clue what I'm doing here.
CC=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-Wall -c

SDIR=src/game/
ODIR=$(SDIR)obj/

banana-ade: $(ODIR)main.o $(ODIR)level.o $(ODIR)tile.o $(ODIR)emptyTile.o $(ODIR)solidTile.o $(ODIR)character.o \
			$(ODIR)playableCharacter.o $(ODIR)banana.o
	$(CC) -o banana-ade $(ODIR)main.o $(ODIR)level.o $(ODIR)tile.o $(ODIR)emptyTile.o $(ODIR)solidTile.o \
	$(ODIR)character.o $(ODIR)playableCharacter.o $(ODIR)banana.o $(LIBS)

$(ODIR)main.o: $(SDIR)main.cpp
	$(CC) $(FLAGS) $(SDIR)main.cpp
	mv main.o $(ODIR)

$(ODIR)character.o: $(SDIR)character.cpp $(SDIR)character.h
	$(CC) $(FLAGS) $(SDIR)character.cpp
	mv character.o $(ODIR)

$(ODIR)playableCharacter.o: $(SDIR)playableCharacter.cpp $(SDIR)playableCharacter.h
	$(CC) $(FLAGS) $(SDIR)playableCharacter.cpp
	mv playableCharacter.o $(ODIR)

$(ODIR)banana.o: $(SDIR)banana.cpp $(SDIR)banana.h
	$(CC) $(FLAGS) $(SDIR)banana.cpp
	mv banana.o $(ODIR)

$(ODIR)level.o: $(SDIR)level.cpp $(SDIR)level.h
	$(CC) $(FLAGS) $(SDIR)level.cpp
	mv level.o $(ODIR)

$(ODIR)tile.o: $(SDIR)tile.cpp $(SDIR)tile.h
	$(CC) $(FLAGS) $(SDIR)tile.cpp
	mv tile.o $(ODIR)

$(ODIR)emptyTile.o: $(SDIR)emptyTile.cpp $(SDIR)emptyTile.h
	$(CC) $(FLAGS) $(SDIR)emptyTile.cpp
	mv emptyTile.o $(ODIR)

$(ODIR)solidTile.o: $(SDIR)solidTile.cpp $(SDIR)solidTile.h
	$(CC) $(FLAGS) $(SDIR)solidTile.cpp
	mv solidTile.o $(ODIR)

.PHONY: clean
clean:
	rm $(ODIR)*.o
