CC = gcc
CCFLAGS = -Wall -Wextra -DUNICODE
CCWARNINGS = -Wno-unused-parameter -Wno-parentheses

PRGM = puissance4
COMPILER = gnu

CLEANLIST = grille.o manip.o game.o console.o entrypoint.o
RESETLIST = puissance4

DEL = rm -f


ifeq ($(OS), Windows_NT)
	DEL = del 
	RESETLIST = puissance4.exe
endif 

ifeq ($(COMPILER), clang)
	CC = clang 
	CCWARNINGS += -Wno-deprecated_declarations
	RESETLIST += puissance4.ilk
	RESETLIST += puissance4.pdb

	ifeq ($(OS), Window_NT)
		PRGM = puissance4.exe
	endif 
endif 

main: prgm 
	$(DEL) $(CLEANLIST)

prgm: grille.o manip.o game.o console.o entrypoint.o
	$(CC) $(CCFLAGS) $(CCWARNINGS) $(CCSTD) -g grille.o manip.o game.o console.o entrypoint.o -o $(PRGM)

entrypoint.o: main.c 
	$(CC) $(CCFLAGS) $(CCWARNINGS) $(CCSTD) -c main.c -o entrypoint.o 

grille.o: grille.c grille.h
	$(CC) $(CCFLAGS) $(CCSTD) -c grille.c -o grille.o

manip.o: manip.c manip.h
	$(CC) $(CCFLAGS) $(CCSTD) -c manip.c -o manip.o

game.o:	game.h game.c
	$(CC) $(CCFLAGS) $(CCSTD) -c game.c -o game.o

console.o: console.c
	$(CC) $(CCWARNINGS) $(CCFLAGS) $(CCSTD) -c console.c -o console.o

clean:
	$(DEL) $(CLEANLIST)

reset: clean 
	$(DEL) $(RESETLIST)