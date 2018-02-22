#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <math.h>

void plot(int x,int y);
void drawcircle(int x,int y,int r);
void dashcircle(int x,int y,int r);

int ox=0;
int oy=0;
int main(void) {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\Program Files");

    setcolor(WHITE);

    int x = getmaxx()/2;
    int y = getmaxy()/2;
    int r = 150;

    putpixel( x, y, WHITE);
    drawcircle(x,y,r-50);

    dashcircle(x,y,r);

    getch();
    closegraph();
    return 0;
}

void drawcircle(int x,int y,int r){
    ox = x;
    oy = y;
    int p = (5/4) - r;

    int x1 = 0;
    int y1 = r;
    plot(x1,y1);
    while(y1>=x1){
        if( p < 0){
            x1 = x1+1;
            plot(x1,y1);
            p = p + 2*x1 + 1;
        }else{
            x1 = x1+1;
            y1 = y1-1;
            plot(x1,y1);
            p = p + 2*x1 - 2*y1 + 1;
        }
    }
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

/*
void dashcircle(int x,int y,int r){
    ox = x;
    oy = y;
    int p = (5/4) - r;
    int l = (int)(r/(sqrt(2.0)));
    printf("%d\n",l);
    int x1 = 0;
    int y1 = r;
    plot(x1,y1);
    int f = 3*l/32;
    while(y1>=x1){
        if( p < 0){
            x1 = x1+1;
            if((f<=3*l/16)||(f == l/4)){
                plot(x1,y1);
                printf("%d\n",f);
            }
            p = p + 2*x1 + 1;
        }else{
            x1 = x1+1;
            y1 = y1-1;
            if((f<=3*l/16)||(f == l/4)){
                plot(x1,y1);
                printf("%d\n",f);
            }
            p = p + 2*x1 - 2*y1 + 1;
        }
        f++;
        if(f == 5*l/16){
            printf("C:%d\n",f);
            f = 0;
        }
    }
}

*/
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
