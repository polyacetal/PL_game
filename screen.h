#ifndef SCREEN_H
#define SCREEN_H
extern int* i_mino(int (*field)[12], int y, int x);
extern void o_mino();
extern void s_mino();
extern void z_mino();
extern void j_mino();
extern void l_mino();
extern void t_mino();
extern void mino(int type, int x, int y);
extern void field();
#endif
