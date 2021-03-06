# Makefile for COMP1927 ass2a 
# Will, Brad, Egene, Oscar, Richard

CC = gcc
CFLAGS = -Wall -Werror -g
BINS = testGameView testHunterView testDracView
LIBS = set.o

all : $(BINS)

testGameView : testGameView.o GameView.o Map.o Places.o set.o
testGameView.o : testGameView.c Globals.h Game.h

testHunterView : testHunterView.o HunterView.o GameView.o Map.o Places.o set.o
testHunterView.o : testHunterView.c Map.c Places.h

testDracView : testDracView.o DracView.o GameView.o Map.o Places.o set.o
testDracView.o : testDracView.c Map.c Places.h

Places.o : Places.c Places.h
Map.o : Map.c Map.h Places.h
GameView.o : GameView.c GameView.h
HunterView.o : HunterView.c HunterView.h
DracView.o : DracView.c DracView.h

set.o : set.c set.h

clean :
	rm -f $(BINS) *.o core

