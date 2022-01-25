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
	drow_point[3][2] = 1;
}

void* S_mino(QUE, DROW, int r) //リストにS型を配置しSミノを再現する
{
	que[0][1] = 1;
	que[1][1] = 1;
	que[1][2] = 1;
	que[2][2] = 1;
	for(int i = 0; i < r; i++){
		Rotate_que(que);
	}
	Drow_point(que, drow_point);
}

void* Z_mino(QUE, DROW, int r) //リストにZ型を配置しZミノを再現する
{
	que[0][1] = 1;
	que[1][1] = 1;
	que[1][0] = 1;
	que[2][0] = 1;
	for(int i = 0; i < r; i++){
		Rotate_que(que);
	}
	Drow_point(que, drow_point);
}

void* J_mino(QUE, DROW, int r) //リストにJ型を配置しJミノを再現する
{
	que[0][1] = 1;
	que[1][1] = 1;
	que[2][1] = 1;
	que[2][0] = 1;
	for(int i = 0; i < r; i++){
		Rotate_que(que);
	}
	Drow_point(que, drow_point);
}

void* L_mino(QUE, DROW, int r) //リストにL型を配置しLミノを再現する
{
	que[0][1] = 1;
	que[1][1] = 1;
	que[2][1] = 1;
	que[2][2] = 1;
	for(int i = 0; i < r; i++){
		Rotate_que(que);
	}
	Drow_point(que, drow_point);
}

void* T_mino(QUE, DROW, int r) //リストにT型を配置しTミノを再現する
{
	que[0][1] = 1;
	que[1][0] = 1;
	que[1][1] = 1;
	que[1][2] = 1;
	for(int i = 0; i < r; i++){
		Rotate_que(que);
	}
	Drow_point(que, drow_point);
}

void Mino(FIELD, DROW, Size *place, int type)
{
	for(int i = 0; i < 4; i++){
		field[Y + drow_point[i][1]][X + drow_point[i][2]] = type;
	}
}

int Mino_check(FIELD, DROW, Size *place)
{
	int flag;
	int y_max;
	int i;
	for(i = 0; i < 4; i++){
		if(y_max < drow_point[i][1])
		y_max = drow_point[i][1];
	}
	for(i = 0; i < 4; i++){
		flag = field[Y + drow_point[i][1]][X + drow_point[i][2]];
		if(flag != 0 && y_max == i) return(3);
		if(flag != 0) return(2);
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
	refresh();
	timeout(-1);
	key = getch();
	if(key == 'q') free(scr);
	return(key);
}

void* Rotate_que(QUE){
	int x, y;
	int rotate_que[3][3] = {}; 

	for(y = 0; y < 3; y ++){
		for(x = 0; x < 3; x ++){
			rotate_que[y][x] = que[x][((y + 1)* 2)% 3];
		}
	}
	for(y = 0; y < 3; y ++){
		for(x = 0; x < 3; x ++){
			que[y][x] = rotate_que[y][x];
		}
	}
} 

void* Drow_point(QUE, DROW){
	int x, y, i;
	i = 0;

	for(y = 0; y < 3; y++){
		for(x = 0; x < 3; x++){
			if(que[y][x] == 1){
				drow_point[i][0] = y;
				drow_point[i][1] = x;
				i++;
			}
		}
	}
}
