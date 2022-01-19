#include "game.h"
#include "screen.h"

int list_num(int (*list)[12], int y, int x)
{
	int type;
	//type = *((list + y) + x);
	type = list[y][x];
	//type = 8;
	return(type);
}

void print_sc(int (*field)[12])
{
	int x, y, type;
	for(x = 0; x <12 ; x++){
		for(y = 0; y < 21; y++){
			type = list_num(field, y, x);
			mino(type, x, y);
		}
	}
}

