#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"
#include "game.h"

void* I_mino(int (*field)[12], int y, int x, int type) //リストにI型を配置しIミノを再現する
{
	field[y][x-1] = type;
	field[y][x] = type;
	field[y][x+1] = type;
	field[y][x+2] = type;
}

void* O_mino(int (*field)[12], int y, int x, int type) //リストにO型を配置しOミノを再現する
{
	field[y][x] = type;
	field[y][x + 1] = type;
	field[y + 1][x] = type;
	field[y + 1][x + 1] = type;
}

void* S_mino(int (*field)[12], int y, int x, int type) //リストにS型を配置しSミノを再現する
{
	field[y][x] = type;
	field[y + 1][x] = type;
	field[y + 1][x + 1] = type;
	field[y + 2][x + 1] = type;
}

void* Z_mino(int (*field)[12], int y, int x, int type) //リストにZ型を配置しZミノを再現する
{
	field[y][x] = type;
	field[y + 1][x] = type;
	field[y + 1][x - 1] = type;
	field[y + 2][x - 1] = type;
}

void* J_mino(int (*field)[12], int y, int x ,int type) //リストにJ型を配置しJミノを再現する
{
	field[y][x] = type;
	field[y + 1][x] = type;
	field[y + 2][x] = type;
	field[y + 2][x - 1] = type;
}

void* L_mino(int (*field)[12], int y, int x, int type) //リストにL型を配置しLミノを再現する
{
	field[y][x] = type;
	field[y + 1][x] = type;
	field[y + 2][x] = type;
	field[y + 2][x + 1] = type;
}

void* T_mino(int (*field)[12], int y, int x, int type) //リストにT型を配置しTミノを再現する
{
	field[y][x] = type;
	field[y + 1][x - 1] = type;
	field[y + 1][x] = type;
	field[y + 1][x + 1] = type;
}

void Mino(int type, int y, int x)
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

