all: tetris

tetris: main.o screen.o game.o
	gcc main.o screen.o game.o -lncursesw -ltinfo -o tetris

main.o: main.c screen.h game.h

screen.o: screen.c screen.h game.h

game.o: game.c game.h screen.h

.c.o:
	gcc -c $<

tgz: distclean
	cd ..; tar zcvf TETRIS-ver.0.1.1.tgz PL_game

clean: 
	-rm *.o

distclean: clean
	-rm tetris

.SUFIXES: .c.o

.PHONY: all
