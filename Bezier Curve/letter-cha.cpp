#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void bezier(int[][2],int);
double combination(int,int,double);
int factorial(int);
int main()
{
    int num1, num2, num3, num4, num5, num6;
    printf("\nEnter the number of points curve 1 has : ");
    scanf("%d",&num1);
    printf("\nEnter the number of points curve 2 has : ");
    scanf("%d",&num2);
    printf("\nEnter the number of points curve 3 has : ");
    scanf("%d",&num3);
    printf("\nEnter the number of points curve 4 has : ");
    scanf("%d",&num4);
    printf("\nEnter the number of points curve 5 has : ");
    scanf("%d",&num5);
    printf("\nEnter the number of points curve 6 has : ");
    scanf("%d",&num6);
    int points1[num1][2], points2[num2][2], points3[num3][2], points4[num4][2], points5[num5][2], points6[num6][2];
    int i,j, gd, gm;
    printf("Enter the points : \n");
    for(i=0; i<num1; i++)
    {
        for(j=0; j<2; j++)
            scanf("%d",&points1[i][j]);
    }
    for(i=0; i<num2; i++)
    {
        for(j=0; j<2; j++)
            scanf("%d",&points2[i][j]);
    }
    for(i=0; i<num3; i++)
    {
        for(j=0; j<2; j++)
            scanf("%d",&points3[i][j]);
    }
    for(i=0; i<num4; i++)
    {
        for(j=0; j<2; j++)
            scanf("%d",&points4[i][j]);
    }
    for(i=0; i<num5; i++)
    {
        for(j=0; j<2; j++)
            scanf("%d",&points5[i][j]);
    }

    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:/Programs Files");

    bezier(points1,num1);
    bezier(points2,num2);
    bezier(points3,num3);
    bezier(points4,num4);
    bezier(points5,num5);
    bezier(points6,num6);

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
