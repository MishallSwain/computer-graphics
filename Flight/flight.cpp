#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define NOR 3
#define NOP 12
#define PI 3.14
int points[NOR][NOP]={{100,200,200,100,180,140,120,140,180,140,120,140}, {170,170,190,190,170,100,120,170,190,260,240,190}, {1,1,1,1,1,1,1,1,1,1,1,1}};
int multiplymat[NOR][NOP];

void draw()
{
    cleardevice();

    for(int i=0; i<12;i++)
    {
        if(i==3 || i==7 || i==11)
            line(points[0][i],points[1][i],points[0][i-3], points[1][i-3]);
        else
            line(points[0][i],points[1][i],points[0][i+1], points[1][i+1]);
    }

    Sleep(200);

}

void move()
{
    int i, j;
    for(i=0; i<NOR; i++)
        for(j=0; j<NOP; j++)
        {
            points[i][j] = multiplymat[i][j];
        }
}

void multiply(float T[NOR][NOR])
{
    int c,d,k;
    float sum=0;

    for (c = 0; c < NOR; c++)
    {
        for (d = 0; d < NOP; d++)
        {
            for (k = 0; k < NOR; k++)
            {
                sum = sum + T[c][k]*points[k][d];
            }


            multiplymat[c][d] = sum;
            sum = 0;
        }
    }
    move();
}


void translate(int Tx, int Ty)
{
    float T[NOR][NOR] = {{1, 0, Tx}, {0, 1, Ty}, {0, 0, 1}};
    multiply(T);
    draw();
}


void rotate(int angle)
{
    float angrad = angle*(PI/180);

    float R[NOR][NOR] = {{cos(angrad), -sin(angrad), 0}, {sin(angrad), cos(angrad), 0}, {0, 0, 1}};
    multiply(R);
    draw();
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    translate(-80,100);
    for(int i=0 ; i<30; i++)
    {
        translate(5,0);
        Sleep(50);
    }

    for(int i=0;;i++)
    {
        rotate(-1);
        translate(i, -pow(i,5/3));
        Sleep(50);
    }

    getch();
    closegraph();
}
