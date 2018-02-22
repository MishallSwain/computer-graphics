#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void bezier(int[][2],int);
double combination(int,int,double);
int factorial(int);
int main()
{
    int points1[3][2] = {
        {20,20},
        {100,200},
        {200,20}
    };
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:/Programs Files");

    bezier(points1,3);


    getch();
}
void bezier(int points[][2], int num)
{
    int i;
    double u,bx,by,c;
    u=0;
    while(u<1)
    {
        bx=0, by=0;
        for(i=0; i<num; i++)
        {
            c = combination(num-1,i,u);
            bx += c * points[i][0];
            by += c * points[i][1];
        }
        printf("bx=%lf \tby=%lf \n---------------------\n",bx,by);
        putpixel(bx,by,WHITE);
        u=u+0.002;
    }
}
double combination(int n, int i, double u)
{
    int n1 = n;
    double comb = factorial(n)/(factorial(i)*factorial(n-i));
    printf("%d %d %lf \t%lf \t%lf \t%lf \n",n,i,u,comb,pow(u,i),pow(1-u,n-i));
    return comb * pow(u,i) * pow(1-u,n-i);
}
int factorial(int n)
{
    int fact=1;
    while(n>0)
    {
        fact = fact*n;
        n--;
    }
    return fact;
}
