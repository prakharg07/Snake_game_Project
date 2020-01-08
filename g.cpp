#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include "g.h"
extern int score;
int snake_length=5;
bool food=true;
int foodX,foodY;
int gridX,gridY;
int posX[20]={20,20,20,20,20},posY[20]={20,19,18,17,16};
short dir=RIGHT;
extern bool gameOver;
void initGrid(int x,int y)
{
    gridX=x;
    gridY=y;
}
void unit(int x,int y)
{
    if(x==0 || y==0 || x== gridX-1 || y==gridY-1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);
    }
    else{
  glLineWidth(1.0);
  glColor3f(1.0,1.0,1.0);
    }
  glBegin(GL_LINE_LOOP);
  glVertex2f(x,y);
  glVertex2f(x+1,y);
  glVertex2f(x+1,y+1);
  glVertex2f(x,y+1);
  glEnd();
}
void drawGrid()
{
    for(int x=0;x<gridX;x++)
    {
        for(int y=0;y<gridY;y++)
        {
            unit(x,y);
        }
    }
}
void drawFood()
{
    if(food)
        random(foodX,foodY);
    food=false;
    glColor3f(1.0,0.0,0.0);
    glRectd(foodX,foodY,foodX+1,foodY+1);
}
void drawSnake()
{
    for(int i=snake_length-1;i>0;i--)
    {
        posX[i]=posX[i-1];
        posY[i]=posY[i-1];
    }
    if(dir==UP)
    {
        posY[0]++;
    }
    else if(dir==DOWN)
    {
        posY[0]--;
    }
    else if(dir==LEFT)
    {
        posX[0]--;
    }
    else if(dir==RIGHT)
    {
        posX[0]++;
    }
    for(int i=0;i<snake_length;i++)
    {
        if(i==0)
            glColor3f(0.0,1.0,0.0);
        else
            glColor3f(0.0,0.0,1.0);
        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }
    for(int j=1;j<snake_length;j++)
{
        if(posX[j]==posX[0] && posY[j]==posY[0])
            gameOver=true;
}
    if(posX[0]==0 || posX[0]==gridX-1 || posY[0]==0 || posY[0]==gridY-1)
    {
        gameOver=true;
    }
    if(posX[0]==foodX && posY[0]==foodY)
    {
        score++;
        snake_length++;
        if(snake_length>MAX)
            snake_length=MAX;
        food=true;
    }
}
void random(int &x,int &y)
{
    int _maxX=gridX-2;
    int _maxY=gridY-2;
    int _min=1;
    srand(time(NULL));
    x=_min+ rand()%(_maxX-_min);
    y=_min+ rand()%(_maxY-_min);

}
