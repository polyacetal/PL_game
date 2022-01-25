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
			Drow(y, x, type);
		}
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

int Random_mino(int shape, FIELD, QUE, DROW, Size *place, int r)
{
	int flag;
	switch(shape){
		case 1:
			I_mino(drow_point, r);
		case 2:
			O_mino(drow_point);
		case 3:
			S_mino(que, drow_point, r);
		case 4:
			Z_mino(que, drow_point, r);
		case 5:
			J_mino(que, drow_point, r);
		case 6:
			L_mino(que, drow_point, r);
		case 7:
			T_mino(que, drow_point, r);
	}
	flag = Mino_check(field, drow_point, place);
	switch(flag){
		case(1):
			Mino(field, drow_point, place, shape);
		case(2):
		return(2);
		case(3):
		return(3);
	}
}

void Reset_mino(int shape, FIELD, QUE, DROW, Size *place, int r)
{
	switch(shape){
		case 1:
			I_mino(drow_point, r);
		case 2:
			O_mino(drow_point);
		case 3:
			S_mino(que, drow_point, r);
		case 4:
			Z_mino(que, drow_point, r);
		case 5:
			J_mino(que, drow_point, r);
		case 6:
			L_mino(que, drow_point, r);
		case 7:
			T_mino(que, drow_point, r);
	}
	Mino(field, drow_point, place, 0);
}

int Game(FIELD, QUE, DROW)
{
	int r, i, flag, key, shape;
	Size *place;
	Move *old;
	srand((unsigned)time(NULL));
	shape = (rand() % 7) + 1;
	Y = 1; 
	X = 5;
	r = 0;
	old -> y = 0;
	old -> x = 0;
	old -> r = 0;

	Random_mino(shape, field, que, drow_point, place, r);
	Print_sc(field);
	Reset_mino(shape, field, que, drow_point, place, r);
	while(1){
		old -> y = Y;
		old -> x = X;
		old -> r = r;
		for(i = 0; i < 1000; i++){
			timeout(1);
			key = getch();
			if(key == 'a') X = X - 1;
			if(key == 'd') X = X + 1;
			if(key == 's') Y = Y + 1;
			if(key == 'q') r = r + 1;
			if(key == 'e') r = r + 3;
			if(key == 'p')return('e') ;
			r = r % 4;
			flag = Random_mino(shape, field, que, drow_point, place, r);
			if(flag == 3)break;
			if(flag == 2){
				Y = old -> y;
				X = old -> x;
				r = old -> r;
			}
			Print_sc(field);
			Reset_mino(shape, field, que, drow_point, place, r);
		}
		if(flag == 3)break;
		Y = Y + 1;
		flag = Random_mino(shape, field, que, drow_point, place, r);
		if(flag == 3)break;
		Print_sc(field);
		Reset_mino(shape, field, que, drow_point, place, r);
	}
	free(drow_point);
}
