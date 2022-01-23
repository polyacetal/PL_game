#ifndef GAME_H
#define GAME_H
#include "screen.h"
#define FIELD int (*field)[12]
extern int List_num(FIELD, int y, int x);
extern void* List_reset(FIELD);
extern void Print_sc(FIELD);
extern void Random_mino(int random, FIELD, int y, int x, int type);
extern int Game();
#endif
