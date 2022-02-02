#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"
#include "game.h"

void* I_mino(DROW, int r) //リストにI型を配置しIミノを再現する
{
	if(r % 2 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = -1;
		drow_point[1][0] = 0;
		drow_point[1][1] = 0;
		drow_point[2][0] = 0;
		drow_point[2][1] = 1;
		drow_point[3][0] = 0;
		drow_point[3][1] = 2;
	}else if(r % 2 == 1){
		drow_point[0][0] = -1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 0;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 0;
		drow_point[3][0] = 2;
		drow_point[3][1] = 0;
	};
}

void* O_mino(DROW) //リストにO型を配置しOミノを再現する
{
	drow_point[0][0] = 0;
	drow_point[0][1] = 0;
	drow_point[1][0] = 0;
	drow_point[1][1] = 1;
	drow_point[2][0] = 1;
	drow_point[2][1] = 0;
	drow_point[3][0] = 1;
	drow_point[3][1] = 1;
}

void* S_mino(DROW, int r) //リストにS型を配置しSミノを再現する
{
	if(r % 4 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 2;
		drow_point[3][0] = 2;
		drow_point[3][1] = 2;
	}else if(r % 4 == 1){
		drow_point[0][0] = 1;
		drow_point[0][1] = 2;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 2;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 0;
	}else if(r % 4 == 2){
		drow_point[0][0] = 0;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	}else if(r % 4 == 3){
		drow_point[0][0] = 1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 0;
		drow_point[2][1] = 1;
		drow_point[3][0] = 0;
		drow_point[3][1] = 2;
	};
}

void* Z_mino(DROW, int r) //リストにZ型を配置しZミノを再現する
{
	if(r % 4 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 0;
		drow_point[3][0] = 2;
		drow_point[3][1] = 0;
	}else if(r % 4 == 1){
		drow_point[0][0] = 0;
		drow_point[0][1] = 0;
		drow_point[1][0] = 0;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 1;
		drow_point[3][1] = 2;
	}else if(r % 4 == 2){
		drow_point[0][0] = 0;
		drow_point[0][1] = 2;
		drow_point[1][0] = 1;
		drow_point[1][1] = 2;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	}else if(r % 4 == 3){
		drow_point[0][0] = 1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 2;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 2;
	};
}

void* J_mino(DROW, int r) //リストにJ型を配置しJミノを再現する
{
	if(r % 4 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 1;
		drow_point[3][1] = 2;
	}else if(r % 4 == 1){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 0;
		drow_point[1][1] = 2;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	}else if(r % 4 == 2){
		drow_point[0][0] = 1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 2;
		drow_point[3][0] = 2;
		drow_point[3][1] = 2;
	}else if(r % 4 == 3){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 2;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 0;
	};
}

void* L_mino(DROW, int r) //リストにL型を配置しLミノを再現する
{
	if(r % 4 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = 2;
		drow_point[1][0] = 1;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 1;
		drow_point[3][1] = 2;
	}else if(r % 4 == 1){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 2;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 2;
	}else if(r % 4 == 2){
		drow_point[0][0] = 1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 2;
		drow_point[3][0] = 2;
		drow_point[3][1] = 0;
	}else if(r % 4 == 3){
		drow_point[0][0] = 0;
		drow_point[0][1] = 0;
		drow_point[1][0] = 0;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	};
}

void* T_mino(DROW, int r) //リストにT型を配置しTミノを再現する
{
	if(r % 4 == 0){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 1;
		drow_point[3][1] = 2;
	}else if(r % 4 == 1){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 2;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	}else if(r % 4 == 2){
		drow_point[0][0] = 1;
		drow_point[0][1] = 0;
		drow_point[1][0] = 1;
		drow_point[1][1] = 1;
		drow_point[2][0] = 1;
		drow_point[2][1] = 2;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	}else if(r % 4 == 3){
		drow_point[0][0] = 0;
		drow_point[0][1] = 1;
		drow_point[1][0] = 1;
		drow_point[1][1] = 0;
		drow_point[2][0] = 1;
		drow_point[2][1] = 1;
		drow_point[3][0] = 2;
		drow_point[3][1] = 1;
	};
}

void Mino(FIELD, DROW, Size *place, int type)
{
	for(int i = 0; i < 4; i++){
		field[Y + drow_point[i][0]][X + drow_point[i][1]] = type;
	}
}

int Mino_check(FIELD, DROW, Size *place, int r, Move *old)
{
	int flag;
	int y_max;
	int i;
	for(i = 0; i< 4; i++){
		flag = field[Y + drow_point[i][0]][X + drow_point[i][1]];
		if(flag != 0){
			if(Y - (old -> y) != 0)return(3);
			if(X - (old -> x) != 0)return(2);
			if(r - (old -> r) != 0)return(2);
		}
	}
	return(1);
}

void Drow(int y, int x, int type)
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

int Title(Size *scr)
{
	int key;
	if (scr == NULL) return('q');
	erase();
	attron(COLOR_PAIR(8) | A_BOLD);
	mvaddstr(H/2 - 4, W/2 - 12, "落ちリス(商標登録回避)");
	attron(COLOR_PAIR(4) | A_BOLD);
	mvaddstr(H/2 + 2, W/2 - 11, "Prease push any key!");
	refresh();
	timeout(-1);
	key = getch();
	if(key == 'q') free(scr);
	return(key);
}
