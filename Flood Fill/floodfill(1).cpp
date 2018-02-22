#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include <math.h>

int ox=0;
int oy=0;
void floodFill(int x,int y,int oldcolor,int newcolor)
{
    if(getpixel(x,y) == oldcolor)
    {
        putpixel(x,y,newcolor);
        floodFill(x+1,y,oldcolor,newcolor);
        floodFill(x,y+1,oldcolor,newcolor);
        floodFill(x-1,y,oldcolor,newcolor);
        floodFill(x,y-1,oldcolor,newcolor);
    }
}
void plot(int x,int y){
    putpixel(ox+x,oy-y,WHITE);
    putpixel(ox-x,oy-y,WHITE);
    putpixel(ox+x,oy+y,WHITE);
    putpixel(ox-x,oy+y,WHITE);
    putpixel(ox+y,oy-x,WHITE);
    putpixel(ox-y,oy-x,WHITE);
    putpixel(ox+y,oy+x,WHITE);
    putpixel(ox-y,oy+x,WHITE);

}
void dashcircle(int x,int y,int r){
    ox = x;
    oy = y;
    int p = (5/4) - r;
    int l = (int)(r/(sqrt(2.0)));
    int x1 = 0;
    int y1 = r;
    plot(x1,y1);
    int f = 0;
    while(y1>=x1){
        if( p < 0){
            x1 = x1+1;
            if((f==0)||(f > l/4)){
                plot(x1,y1);
            }
            p = p + 2*x1 + 1;
        }else{
            x1 = x1+1;
            y1 = y1-1;
            if((f==0)||(f > l/4)){
                plot(x1,y1);
            }
            p = p + 2*x1 - 2*y1 + 1;
        }
        f++;
        if(f == 3*l/4){
            f = 0;
        }
    }
}

int main()
{
    int gm,gd=DETECT,radius;
    int x,y;

    printf("Enter x and y positions for circle\n");
    scanf("%d%d",&x,&y);
    printf("Enter radius of circle\n");
    scanf("%d",&radius);

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    circle(x,y,radius);
    dashcircle(x,y,radius+80);
    floodFill(x,y,0,15);
    getch();
    closegraph();

    return 0;
}
