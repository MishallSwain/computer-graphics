#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void plot(int x1,int y1,int x2,int y2);
void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
int main(void) {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\Program Files");

    setcolor(WHITE);

    int ox = getmaxx()/2;
    int oy = getmaxy()/2;
    int mx = getmaxx();
    int my = getmaxy();

    plot(ox,0,ox,my);
    plot(0,oy,mx,oy);

    rect(ox+20,oy-20,ox+300,oy-20,ox+300,oy-180,ox+20,oy-180);
    rect(ox+20,oy-20,ox+120,oy-20,ox+120,oy-85,ox+20,oy-85);
    rect(ox+20,oy-115,ox+120,oy-115,ox+120,oy-180,ox+20,oy-180);
    rect(ox+150,oy-20,ox+300,oy-20,ox+300,oy-85,ox+150,oy-85);
    rect(ox+150,oy-115,ox+300,oy-115,ox+300,oy-180,ox+150,oy-180);

    //floodfill(ox+130,oy-100,WHITE);
    //floodfill(ox+50,oy-40,RED);

    getch();
    closegraph();
    return 0;

}

void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){

    plot(x1,y1,x2,y2);
    plot(x2,y2,x3,y3);
    plot(x3,y3,x4,y4);
    plot(x4,y4,x1,y1);
}

void plot(int x1,int y1,int x2,int y2){

    int x = abs(x2 - x1);
    int y = abs(y2 - y1);
    int signx = x2 >= x1 ? 1 : -1;
    int signy = y2 >= y1 ? 1 : -1;
    int flag = 0;
    if( y > x){
        int t = x;
        x = y;
        y = t;
        flag = 1;
    }

    int p = 2*y - x;
    putpixel( x1, y1, WHITE);

    int x0 = x1;
    int y0 = y1;
    int i;
    for(i=0;i<x;i++){
        if( p < 0){
            if(flag == 0){
                x0 = x0+signx;
                putpixel( x0, y0, WHITE);
            }else{
                y0 = y0+signy;
                putpixel( x0, y0, WHITE);
            }
            p = p + 2*y;
        }else{
            x0 = x0+signx;
            y0 = y0+signy;
            putpixel( x0, y0, WHITE);
            p = p + 2*y - 2*x;
        }
    }
}
