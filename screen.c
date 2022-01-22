#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"
#include "game.h"

void* I_mino(int (*field)[12], int y, int x) //リストにI型に1を配置しIミノを再現する
{
	int *list;
	field[y][x-1] = 1;
	field[y][x] = 1;
	field[y][x+1] = 1;
	field[y][x+2] = 1;
	list = *field;
}

void* O_mino(int (*field)[12], int y, int x) //リストにO型に2を配置しOミノを再現する
{
	int *list;
	field[y][x] = 2;
	field[y][x + 1] = 2;
	field[y + 1][x] = 2;
	field[y + 1][x + 1] = 2;
}

void* S_mino(int (*field)[12], int y, int x) //リストにS型に3を配置しSミノを再現する
{
	int *list;
	field[y][x] = 3;
	field[y + 1][x] = 3;
	field[y + 1][x + 1] = 3;
	field[y + 2][x + 1] = 3;
}

void* Z_mino(int (*field)[12], int y, int x) //リストにZ型に4を配置しZミノを再現する
{
	int *list;
	field[y][x] = 4;
	field[y + 1][x] = 4;
	field[y + 1][x - 1] = 4;
	field[y + 2][x - 1] = 4;
}

void* J_mino(int (*field)[12], int y, int x) //リストにJ型に5を配置しJミノを再現する
{
	int *list;
	field[y][x] = 5;
	field[y + 1][x] = 5;
	field[y + 2][x] = 5;
	field[y + 2][x - 1] = 5;
}

void* L_mino(int (*field)[12], int y, int x) //リストにL型に6を配置しLミノを再現する
{
	int *list;
	field[y][x] = 6;
	field[y + 1][x] = 6;
	field[y + 2][x] = 6;
	field[y + 2][x + 1] = 6;
}

void* T_mino(int (*field)[12], int y, int x) //リストにT型に7を配置しTミノを再現する
{
	int *list;
	field[y][x] = 7;
	field[y + 1][x - 1] = 7;
	field[y + 1][x] = 7;
	field[y + 1][x + 1] = 7;
}

void Mino(int type, int x, int y)
{
	x = x*2;
	x = x+10;
	y = y+5;
	if(type == 0){
		attron(COLOR_PAIR(8) | A_BOLD);
		mvaddstr(y, x, "□");
	}else{
		attron(COLOR_PAIR(type) | A_BOLD);
		mvaddstr(y, x, "■");
	}
}

Size *Get()
{
	Size *scr;
	scr = (Size *)malloc(sizeof(Size));
	if(scr == NULL) return(NULL);
	getmaxyx(stdscr, scr->h, scr->w);
	return(scr);
}

int Title(Size *scr)
{
	int key;
	if (scr == NULL) return('q');
	erase();
	attron(COLOR_PAIR(8) | A_BOLD);
	mvaddstr((scr -> h)/2 - 4, (scr -> w)/2 - 12, "落ちリス(商標登録回避)");
	refresh();
	timeout(-1);
	key = getch();
	if(key == 'q') free(scr);
	return(key);
}

