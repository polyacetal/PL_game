#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include "game.h"
#include "screen.h"

int List_num(FIELD, int y, int x) //指定されたy行x列の要素を返す
{
	int type;
	type = field[y][x]; //1,i,水;2,o,黄;3,s,緑;4,z,赤;5,j,青;6,l,橙;7,t,白;
	return(type);
}

void* List_reset(FIELD) //2次元配列を縁枠だけの初期状態に戻す
{
	int x, y;
	for(y = 0; y < 19; y++){
		for(x = 1; x < 11; x++){
			field[y][x] = 0;
		}
	}
}

void Print_sc(FIELD) //2次元配列をもとにフィールドを表示する
{
	int x, y, type;
	erase();
	for(x = 0; x <12 ; x++){
		for(y = 0; y < 21; y++){
			type = List_num(field, y, x);
			Mino(type, y, x);
		}
	}
}

void Random_mino(int shape, FIELD, int y, int x, int type)
{
	switch(shape){
		case 1:
			I_mino(field, y, x, type);
		case 2:
			O_mino(field, y, x, type);
		case 3:
			S_mino(field, y, x, type);
		case 4:
			Z_mino(field, y, x, type);
		case 5:
			J_mino(field, y, x, type);
		case 6:
			L_mino(field, y, x, type);
		case 7:
			T_mino(field, y, x, type);
	}

}

int Game(FIELD)
{
	int x, y, i, key, shape;
	srand((unsigned)time(NULL));
	shape = (rand() % 7) + 1;
	y = 0; 
	x = 5;

	while(1){
		Random_mino(shape, field, y, x, shape);
		Print_sc(field);
		Random_mino(shape, field, y, x, 0);
		for(i = 0; i < 1000; i++){
			timeout(1);
			key = getch();
			if(key == 'a') x = x - 1;
			if(key == 'd') x = x + 1;
			if(key == 's') y = y + 1;
			if(y >= 18) return('q');
			Random_mino(shape, field, y, x, shape);
			Print_sc(field);
			Random_mino(shape, field, y, x, 0);
		}
		y = y + 1;
		if(y >= 18) return('q');
		Print_sc(field);
	}
}
