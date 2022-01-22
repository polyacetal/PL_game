#ifndef GAME_H
#define GAME_H
#include "screen.h"
extern int List_num(int (*list)[12], int y, int x);
extern void* List_reset(int (*field)[12]);
extern void Print_sc(int(*field)[12]);
#endif
