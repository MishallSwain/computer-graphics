#include<stdio.h>
#include<graphics.h>

int cx;
int cy;

/*inner circle fill by any boundry or floodfill
outer circle to be filled in cyan color do with flood
*/

void myRectangle(int x,int y, int x1,int y1)
{
    rectangle(cx+x,cy-y,cx+x1,cy-y1);
}

void f_fill(int x,int y, int fg, int bg)
{
    int current = getpixel(x,y);
    if(current == bg)
    {
        //delay(2);
        putpixel(x,y,fg);
        f_fill(x+1,y,fg,bg);
        f_fill(x-1,y,fg,bg);
        f_fill(x,y+1,fg,bg);
        f_fill(x,y-1,fg,bg);
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"");
    cx=getmaxx()/2;
    cy=getmaxy()/2;
    setlinestyle(0,0,3);

    /*FIGURE 1*/
    setcolor(YELLOW);
    circle(cx+0,cy-0,80);
    f_fill(cx+55,cy-55,11,0);

    initgraph(&gd,&gm,"");

    /*FIGURE 2*/
    setlinestyle(0,0,3);
    setcolor(RED);
    circle(cx+0,cy-0,50);
    f_fill(cx+0,cy-0,14,0);
    setcolor(YELLOW);
    circle(cx+0,cy-0,80);
    f_fill(cx+55,cy-55,11,0);

    initgraph(&gd,&gm,"");

    /*FIGURE 3*/
    setlinestyle(0,0,3);
    setcolor(GREEN);
    line(20,150,200,150);
    setlinestyle(0,0,5);
    setcolor(BLUE);
    line(200,150,200,20);
    setlinestyle(0,0,3);
    setcolor(YELLOW);
    line(200,20,20,20);
    setlinestyle(0,0,5);
    setcolor(RED);
    line(20,20,20,150);
    f_fill(25,25,13,0);

    initgraph(&gd,&gm,"");

    /*FIGURE 4*/
    setlinestyle(0,0,3);
    setcolor(GREEN);
    line(20,150,200,150);
    setlinestyle(0,0,5);
    setcolor(BLUE);
    line(200,150,200,20);
    setlinestyle(0,0,3);
    setcolor(YELLOW);
    line(200,20,20,20);
    setlinestyle(0,0,5);
    setcolor(RED);
    line(20,20,20,150);
    setlinestyle(0,0,3);
    circle(110,85,20);
    f_fill(110,85,15,0);
    f_fill(25,25,13,0);
    getch();
    return 0;
}

