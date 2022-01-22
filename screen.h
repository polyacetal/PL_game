#ifndef SCREEN_H
#define SCREEN_H
typedef struct {
	int w, h;
} Size;
extern void* I_mino(int (*field)[12], int y, int x);
extern void* O_mino(int (*field)[12], int y, int x);
extern void* S_mino(int (*field)[12], int y, int x);
extern void* Z_mino(int (*field)[12], int y, int x);
extern void* J_mino(int (*field)[12], int y, int x);
extern void* L_mino(int (*field)[12], int y, int x);
extern void* T_mino(int (*field)[12], int y, int x);
extern void Mino(int type, int x, int y);
extern Size *Get();
extern int Title(Size *scr);
#endif
