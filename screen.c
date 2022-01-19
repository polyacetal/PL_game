#include <ncurses.h>
#include "screen.h"
#include "game.h"

void i_mino()
{
	attron(COLOR_PAIR(1) | A_BOLD);
	mvaddstr(5, 20, "■ ■ ■ ■ ");
}

void o_mino()
{
	attron(COLOR_PAIR(2) | A_BOLD);
	mvaddstr(8, 20, "■ ■ ");
	mvaddstr(9, 20, "■ ■ " );
}

void s_mino()
{
	attron(COLOR_PAIR(3) | A_BOLD);
	mvaddstr(12, 22, "■ ■ ");
	mvaddstr(13, 20, "■ ■ ");
}

void z_mino()
{
	attron(COLOR_PAIR(4) | A_BOLD);
	mvaddstr(16, 20, "■ ■ ");
	mvaddstr(17, 22, "■ ■ ");
}

void j_mino()
{
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(20, 20, "■ ");
	mvaddstr(21, 20, "■ ■ ■ ");
}

void l_mino()
{
	attron(COLOR_PAIR(6) | A_BOLD);
	mvaddstr(24, 24, "■ ");
	mvaddstr(25, 20, "■ ■ ■ ");
}

void t_mino()
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(28, 22, "■ ");
	mvaddstr(29, 20, "■ ■ ■ ");
}

void mino(int type, int x, int y)
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

void field()
{
	int i,j;
	attron(COLOR_PAIR(8) | A_BOLD);
	for(i = 0; i < 13; i++){
		j = i*2 + 10;
		mvaddstr(5, j, "■");
		mvaddstr(26, j, "■");
	}
	for(i = 0; i < 20; i++){
		j = i + 6;
		mvaddstr(j, 10, "■");
		mvaddstr(j, 34, "■");
	}
}

void draw()
{
	
}

