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
	for(y = 0; y < 20; y++){
		field[y][0] = 8;
		for(x = 1; x < 11; x++){
			field[y][x] = 0;
		}
		field[y][11] = 8;
	}
	for(x = 0; x < 12; x++){
		field[20][x] = 8;
	}
	return(field);
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

int Random_mino(int shape, FIELD, DROW, Size *place, int r, Move *old)
{
	int flag;
	switch(shape){
		case 1:
			I_mino(drow_point, r);
			break;
		case 2:
			O_mino(drow_point);
			break;
		case 3:
			S_mino(drow_point, r);
			break;
		case 4:
			Z_mino(drow_point, r);
			break;
		case 5:
			J_mino(drow_point, r);
			break;
		case 6:
			L_mino(drow_point, r);
			break;
		case 7:
			T_mino(drow_point, r);
			break;
	}
	flag = Mino_check(field, drow_point, place, r, old);
	switch(flag){
		case(1):
			Mino(field, drow_point, place, shape);
			return(1);
		case(2):
			return(2);
		case(3):
			return(3);
	}
}

int Mino_drop(FIELD, DROW, int shape)
{
	int r, i, flag, key;
	Size *place;
	Move *old;
	place = (Size *)malloc(sizeof(Size));
	old = (Move *)malloc(sizeof(Move));
	flag = 0;
	Y = 1; 
	X = 4;
	r = 0;
	old -> y = 0;
	old -> x = 0;
	old -> r = 0;

	Random_mino(shape, field, drow_point, place, r, old);
	Print_sc(field);
	Mino(field, drow_point, place, 0);
	while(1){
		for(i = 0; i < 1000; i++){
			old -> y = Y;
			old -> x = X;
			old -> r = r;
			timeout(1);
			key = getch();
			if(key == 'a') X = X - 1;
			if(key == 'd') X = X + 1;
			if(key == 's') Y = Y + 1;
			if(key == 'e') r = r + 1;
			if(key == 'q') r = r + 3;
			if(key == 'p') return(0);
			r = r % 4;
			flag = Random_mino(shape, field, drow_point, place, r, old);
			if(flag == 3){
				Y = old -> y;
				X = old -> x;
				r = old -> r;
				return(1);
			}
			if(flag == 2){
				Y = old -> y;
				X = old -> x;
				r = old -> r;
			}
			Print_sc(field);
			Mino(field, drow_point, place, 0);
		}
		Y = Y + 1;
		flag = Random_mino(shape, field, drow_point, place, r, old);
		if(flag == 3){
			Y = old -> y;
			X = old -> x;
			r = old -> r;
			return(1);
		}
		Print_sc(field);
		Mino(field, drow_point, place, 0);
	}
	return(1);
	free(place);
	free(old);
}

int Game(FIELD, DROW)
{
	int flag, shape;	
	flag = 1;	
	field = List_reset(field);
	srand((unsigned int)time(NULL));
	

	while(1){
	Print_sc(field);
	shape = rand() % 7 + 1;
	//shape = 1;
	flag = Mino_drop(field, drow_point, shape);
	if(flag == 0)break;
	}
	return(flag);
}