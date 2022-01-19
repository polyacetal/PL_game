all: main

main: main.o screen.o game.o
	gcc main.o screen.o game.o -lncursesw -ltinfo -o main

main.o: main.c screen.h game.h

screen.o: screen.c screen.h game.h

game.o: game.c game.h screen.h

.c.o:
	gcc -c $<

.SUFIXES: .c.o

.PHONY: all
