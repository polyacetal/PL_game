#ifndef SCREEN_H
#define SCREEN_H
typedef struct {
	int w, h;
} Size;
extern void* I_mino(int (*field)[12], int y, int x, int type);
extern void* O_mino(int (*field)[12], int y, int x, int type);
extern void* S_mino(int (*field)[12], int y, int x, int type);
extern void* Z_mino(int (*field)[12], int y, int x, int type);
extern void* J_mino(int (*field)[12], int y, int x, int type);
extern void* L_mino(int (*field)[12], int y, int x, int type);
extern void* T_mino(int (*field)[12], int y, int x, int type);
extern void Mino(int type, int y, int x);
extern Size *Get();
extern int Title(Size *scr);
#endif
