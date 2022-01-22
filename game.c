#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>
#include "game.h"
#include "screen.h"

int List_num(int (*list)[12], int y, int x) //指定されたy行x列の要素を返す
{
	int type;
	type = list[y][x]; //1,i,水;2,o,黄;3,s,緑;4,z,赤;5,j,青;6,l,橙;7,t,白;
	return(type);
}

void* List_reset(int (*field)[12]) //2次元配列を縁枠だけの初期状態に戻す
{
	int x, y;
	for(y = 0; y < 19; y++){
		for(x = 1; x < 11; x++){
			field[y][x] = 0;
		}
	}
}

void Print_sc(int (*field)[12]) //2次元配列をもとにフィールドを表示する
{
	int x, y, type;
	erase();
	for(x = 0; x <12 ; x++){
		for(y = 0; y < 21; y++){
			type = List_num(field, y, x);
			Mino(type, x, y);
		}
	}
}

