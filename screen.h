#ifndef SCREEN_H
#define SCREEN_H
#include "game.h"
extern void* I_mino(DROW, int r);
extern void* O_mino(DROW);
extern void* S_mino(QUE, DROW, int r);
extern void* Z_mino(QUE, DROW, int r);
extern void* J_mino(QUE, DROW, int r);
extern void* L_mino(QUE, DROW, int r);
extern void* T_mino(QUE, DROW, int r);
extern void Mino(FIELD, DROW, Size *place,  int type);
extern int Mino_check(FIELD, DROW, Size *place);
extern void Drow(int y, int x, int type);
extern int Title(Size *scr);
extern void* Rotate_que(QUE);
extern void* Drow_point(QUE, DROW);
#endif
