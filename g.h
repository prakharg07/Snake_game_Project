#ifndef G_H_INCLUDED
#define G_H_INCLUDED
#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define MAX 60
void initGrid(int,int);
void drawGrid();
void drawSnake();
void drawFood();
void random(int& ,int&);
#endif // G_H_INCLUDED