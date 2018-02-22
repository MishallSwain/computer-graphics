#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int xc,yc;

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

void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){

    plot(xc+x1,yc-y1,xc+x2,yc-y2);
    plot(xc+x2,yc-y2,xc+x3,yc-y3);
    plot(xc+x3,yc-y3,xc+x4,yc-y4);
    plot(xc+x4,yc-y4,xc+x1,yc-y1);
}

void drawAxis(int x1,int y1,int x2,int y2,int cx,int cy)
{
    float dx,dy,l,ix,iy,x,y;
    int i;
    dx=x2-x1;
    dy=y2-y1;
    l=(abs(dx)>abs(dy))?abs(dx):abs(dy);
    ix=dx/l;
    iy=dy/l;
    x=x1;
    y=y1;
    putpixel(x+cx,y+cy,WHITE);
    for(i=0;i<l-1;i++)
    {
        x=x+ix;
        y=y+iy;
        if(i%10!=0 && (i-1)%10!=0 && (i-2)%10!=0)
            putpixel(x+cx,y+cy,WHITE);
    }
    putpixel(x2+cx,y2+cy,WHITE);
}

void Transform(int p[3][20], float t[3][3])
{
    int i,j,k,sum=0,c[3][20];
    for(i=0;i<3;i++)
        for(j=0;j<20;j++)
            c[i][j]=0;

    for(i=0;i<3;i++)
        for(j=0;j<20;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
                sum=sum+t[i][k]*p[k][j];
            c[i][j]=sum;
        }
    for(i=0;i<17;i=i+4)
        rect(c[0][i],c[1][i],c[0][i+1],c[1][i+1],c[0][i+2],c[1][i+2],c[0][i+3],c[1][i+3]);
}

int main()
{
    int gd = DETECT, gm,i,ch;
    float tx,ty,a;
    int p[3][20]=
    {
        {20,300,300,20,20,120,120,20,20,120,120,20,150,300,300,150,150,300,300,150},
        {20,20,180,180,20,20,85,85,115,115,180,180,20,20,85,85,115,115,180,180},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    initgraph(&gd, &gm, "C:\\TurboC++\\Disk\\TurboC3\\BGI");
    xc=getwindowwidth()/2;
    yc=getwindowheight()/2;
    drawAxis(0,yc,2*xc,yc,0,0);
    drawAxis(xc,0,xc,2*yc,0,0);
    for(i=0;i<17;i=i+4)
        rect(p[0][i],p[1][i],p[0][i+1],p[1][i+1],p[0][i+2],p[1][i+2],p[0][i+3],p[1][i+3]);
    outtextxy(20,30,"Original Image" );
    do
    {
        printf("\n\n****** MENU *****");
        printf("\n1.Translation");
        printf("\n2.Rotation");
        printf("\n3.Scaling");
        printf("\n4.Reflection");
        printf("\n5.Shearing");
        printf("\n6.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);
        initgraph(&gd, &gm, "C:\\TurboC++\\Disk\\TurboC3\\BGI");
        drawAxis(0,yc,2*xc,yc,0,0);
        drawAxis(xc,0,xc,2*yc,0,0);
        system("cls");
        switch(ch)
        {
            case 1 :
            {
                printf("\n\nEnter units of translation in X-direction : ");
                scanf("%f",&tx);
                printf("\n\nEnter units of translation in Y-direction : ");
                scanf("%f",&ty);
                float t[3][3] = {{1,0,tx},{0,1,ty},{0,0,1}};
                Transform(p,t);
                outtextxy(20,30,"Translation");
                break;
            }
            case 2 :
            {
                system("cls");//clrscr();
                printf("\n\nEnter angle of rotation (in degrees) : ");
                scanf("%f",&a);
                a=(a*M_PI)/180;
                float t[3][3] = {{cos(a),-sin(a),0},{sin(a),cos(a),0},{0,0,1}};
                Transform(p,t);
                outtextxy(20,30,"Rotation");
                break;
            }
            case 3 :
            {
                system("cls");//clrscr();
                printf("\n\nEnter Scaling units in X-direction : ");
                scanf("%f",&tx);
                printf("\n\nEnter Scaling units in Y-direction : ");
                scanf("%f",&ty);
                float t[3][3] = {{tx,0,0},{0,ty,0},{0,0,1}};
                Transform(p,t);
                outtextxy(20,30,"Scaling");
                break;
            }
            case 4 :
            {
                printf("\n1.Reflect about x-axis");
                printf("\n2.Reflect about y-axis");
                printf("\n3.Reflect about origin");
                printf("\n\nEnter your choice : ");
                scanf("%d",&ch);
                float t[3][3] = {{1,0,0},{0,1,0},{0,0,1}};;
                if(ch==1)
                    t[1][1] = -1;
                else if(ch==2)
                    t[0][0] = -1;
                else if(ch==3)
                {
                    t[1][1] = -1;
                    t[0][0] = -1;
                }
                else
                    printf("\n\nINVALID INPUT");
                Transform(p,t);
                outtextxy(20,30,"Reflection");
                break;
            }
            case 5 :
            {
                printf("\n\nEnter Shearing factor in X-direction : ");
                scanf("%f",&tx);
                printf("\n\nEnter Shearing factor in Y-direction : ");
                scanf("%f",&ty);
                float t[3][3] = {{1,ty,0},{tx,1,0},{0,0,1}};
                Transform(p,t);
                outtextxy(20,30,"Sheering");
                break;
            }
            case 6 :
                break;
            default:
                printf("\n\nINVALID INPUT");
        }
        system("cls");
    }while(ch!=6);
}
