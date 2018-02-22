#include<stdio.h>
#include<graphics.h>
#include<dos.h>

void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryfill(x+1,y,f_color,b_color);
        boundaryfill(x,y+1,f_color,b_color);
        boundaryfill(x-1,y,f_color,b_color);
        boundaryfill(x,y-1,f_color,b_color);
        boundaryfill(x+1,y+1,f_color,b_color);
        boundaryfill(x+1,y-1,f_color,b_color);
        boundaryfill(x-1,y+1,f_color,b_color);
        boundaryfill(x-1,y-1,f_color,b_color);
    }
}

int main()
{
    int gm,gd=DETECT,radius;
    int x,y;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(15);

	setlinestyle(0,0,3);
	circle(200,200,50);

	circle(200,200,100);

    boundaryfill(251,251,14,15);
    boundaryfill(215,215,0,15);

    delay(100);
	system("pause");
	return 0;
}
