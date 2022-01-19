#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include "screen.h"
#include "game.h"

#define COLOR_ORANGE 1

int main(void)
{
	setlocale(LC_ALL, "");
	initscr();
	int (*field)[12] = malloc(sizeof(int)*21*12);
	int x, y;

	start_color();
	init_color(COLOR_ORANGE, 243, 152, 0);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_ORANGE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	bkgd(COLOR_PAIR(8));

	erase();
	
	for(y = 0; y < 20; y++){
		field[y][0] = 8;
		for(x = 1; x <11 ; x++){
			field[y][x] = 0;
		}
		field[y][11] = 8;
	}
	for(x = 0; x <12 ; x++){
		field[20][x] = 8;
	}
	print_sc(field);

	refresh();

	timeout(-1);
	getch();

	endwin();
	free(field);
	return(0);
}
