#include <stdio.h>
#include <graphics.h>

void lineB(int x1,int y1,int x2,int y2){
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

void lineD(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,WHITE);  // put pixel at (X,Y)
        X += Xinc;       	// increment in x at each step
        Y += Yinc;       	// increment in y at each step
    }
}


int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TurboC");

    lineB(20,20,200,200);
    lineD(20,200,200,20);
    getch();
    return 0;
}
