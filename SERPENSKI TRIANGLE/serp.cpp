#include<stdio.h>
#include<graphics.h>

void dtri(int x1, int y1, int x2, int y2, int x3, int y3)
{
if(x1-x2 > 4)
{
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
dtri(x1,y1,(x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
dtri((x1+x2)/2, (y1+y2)/2,x2,y2, (x2+x3)/2, (y2+y3)/2);
dtri((x1+x3)/2, (y1+y3)/2,(x2+x3)/2, (y2+y3)/2, x3, y3);
}
}

int main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,"");
dtri(getmaxx()/2, 0, 0, getmaxy(), getmaxx(), getmaxy());
getch();
closegraph();
return(0);
}
