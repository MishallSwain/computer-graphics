#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void floodFill(int x, int y, int old, int fill)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill);
        floodFill(x+1,y,old,fill);
		floodFill(x-1,y,old,fill);
		floodFill(x, y+1,old,fill);
        floodFill(x,y-1,old,fill);
        floodFill(x+1,y+1,old,fill);
        floodFill(x+1,y-1,old,fill);
        floodFill(x-1,y+1,old,fill);
        floodFill(x-1,y-1,old,fill);
	}
}


int main(){
	initwindow(700,700);
	setcolor(15);

	setlinestyle(0,0,3);
	circle(200,200,50);

	circle(200,200,100);

	floodFill(251,251,0,14);
	floodFill(215,215,0,15);

	delay(100);
	system("pause");
	return 0;
}
