#ifndef GAME_H
#define GAME_H
#define FIELD int (*field)[12]
#define QUE int (*que)[3]
#define DROW int (*drow_point)[4]
typedef struct {
	int w, h;
} Size;
typedef struct {
	int y, x, r;
} Move;
#define X (place -> w)
#define Y (place -> h)
#define H (scr -> h)
#define W (scr -> w)
extern int List_num(FIELD, int y, int x);
extern void* List_reset(FIELD);
extern void Print_sc(FIELD);
extern Size *Get();
extern int Random_mino(int shape, FIELD, QUE, DROW, Size *place, int r);
extern void Reset_mino(int shape, FIELD, QUE, DROW, Size *place, int r);
extern int Game(FIELD, QUE, DROW);
#endif
