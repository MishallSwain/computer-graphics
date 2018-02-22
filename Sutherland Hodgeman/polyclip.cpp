#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define OUT2IN  1
#define IN      2
#define IN2OUT  3
#define OUT     4
#define INVALID 5

int poly[100];
int tempPoly[100];
int sides;

int xmin,ymin,xmax,ymax;

int clipLeft(int x,int x1,int x2)
{
    if(x1<x && x2>=x)
        return OUT2IN;
    else if(x1>=x && x2>=x)
        return IN;
    else if(x1>=x && x2<x)
        return IN2OUT;
    else if(x1<x && x2<x)
        return OUT;
    else
        return INVALID;
}

int clipBottom(int y,int y1,int y2)
{
    if(y1<y && y2>=y)
        return OUT2IN;
    else if(y1>=y && y2>=y)
        return IN;
    else if(y1>=y && y2<y)
        return IN2OUT;
    else if(y1<y && y2<y)
        return OUT;
    else
        return INVALID;
}
int clipRight(int x,int x1,int x2)
{
    if(x1>x && x2<=x)
        return OUT2IN;
    else if(x1<=x && x2<=x)
        return IN;
    else if(x1<=x && x2>x)
        return IN2OUT;
    else if(x1>x && x2>x)
        return OUT;
    else
        return INVALID;
}

int clipTop(int y,int y1,int y2)
{
    if(y1>y && y2<=y)
        return OUT2IN;
    else if(y1<=y && y2<=y)
        return IN;
    else if(y1<=y && y2>y)
        return IN2OUT;
    else if(y1>y && y2>y)
        return OUT;
    else
        return INVALID;
}

void leftClipper()
{
    int orientation;
    int incrside = 0;
    int j=0;
    int cx,cy;
    int x1,y1,x2,y2;
    int i;

    for(i=0;i<sides*2;i=i+2)
    {
        x1 = poly[i];
        y1 = poly[i+1];

        x2 = poly[i+2];
        y2 = poly[i+3];

        orientation = clipLeft(xmin,x1,x2);

        switch(orientation)
        {
            case OUT2IN:
                    cx = xmin;
                    cy = y1 + (float)(y2 - y1) * (float)(xmin - x1)/(float)(x2 - x1);

                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;

                    incrside++;
                    break;
            case IN:
                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;
                    break;
            case IN2OUT:
                    cx = xmin;
                    cy = y1 + (float)(y2 - y1) * (xmin - x1)/(float)(x2 - x1);

                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    break;
            case OUT:
                    incrside--;
                    break;
        }
    }

    sides = sides + incrside;

    for(i=0;i<sides*2;i=i+2)
    {
        poly[i] = tempPoly[i];
        poly[i+1] = tempPoly[i+1];
    }

    poly[i]   = poly[0];
    poly[i+1] = poly[1];
}

void bottomClipper()
{
    int orientation;
    int incrside = 0;
    int j=0;
    int cx,cy;
    int x1,y1,x2,y2;
    int i;

    for(i=0;i<sides*2;i=i+2)
    {
        x1 = poly[i];
        y1 = poly[i+1];
        x2 = poly[i+2];
        y2 = poly[i+3];

        orientation = clipBottom(ymin,y1,y2);

        switch(orientation)
        {
            case OUT2IN:
                    cx = x1 + (float)(ymin - y1) * (x2 - x1) / (y2 - y1);
                    cy = ymin;
                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;

                    incrside++;
                    break;
            case IN:
                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;
                    break;
            case IN2OUT:
                    cx = x1 + (float)(ymin - y1) * (x2 - x1) / (y2 - y1);
                    cy = ymin;

                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    break;
            case OUT:
                    incrside--;
                    break;
        }
    }

    sides = sides + incrside;

    for(i=0;i<sides*2;i=i+2)
    {
        poly[i] = tempPoly[i];
        poly[i+1] = tempPoly[i+1];
    }

    poly[i]   = poly[0];
    poly[i+1] = poly[1];
}

void rightClipper()
{
    int orientation;
    int incrside = 0;
    int j=0;
    int cx,cy;
    int x1,y1,x2,y2;
    int i;

    for(i=0;i<sides*2;i=i+2)
    {
        x1 = poly[i];
        y1 = poly[i+1];
        x2 = poly[i+2];
        y2 = poly[i+3];

        orientation = clipRight(xmax,x1,x2);

        switch(orientation)
        {
            case OUT2IN:
                    cx = xmax;
                    cy = y1 + (float)(y2 - y1) * (float)(xmax - x1)/(float)(x2 - x1);
                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;

                    incrside++;
                    break;
            case IN:
                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;
                    break;
            case IN2OUT:
                    cx = xmax;
                    cy = y1 + (float)(y2 - y1) * (xmax - x1)/(float)(x2 - x1);

                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    break;
            case OUT:
                    incrside--;
                    break;
        }
    }

    sides = sides + incrside;

    for(i=0;i<sides*2;i=i+2)
    {
        poly[i] = tempPoly[i];
        poly[i+1] = tempPoly[i+1];
    }

    poly[i]   = poly[0];
    poly[i+1] = poly[1];
}

void topClipper()
{
    int orientation;
    int incrside = 0;
    int j=0;
    int cx,cy;
    int x1,y1,x2,y2;
    int i;

    for(i=0;i<sides*2;i=i+2)
    {
        x1 = poly[i];
        y1 = poly[i+1];
        x2 = poly[i+2];
        y2 = poly[i+3];

        orientation = clipTop(ymax,y1,y2);

        switch(orientation)
        {
            case OUT2IN:
                    cx = x1 + (float)(ymax - y1) * (x2 - x1) / (y2 - y1);
                    cy = ymax;
                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;

                    incrside++;
                    break;
            case IN:
                    tempPoly[j]   = x2;
                    tempPoly[j+1] = y2;
                    j = j+2;
                    break;
            case IN2OUT:
                    cx = x1 + (float)(ymax - y1) * (x2 - x1) / (y2 - y1);
                    cy = ymax;

                    tempPoly[j]   = cx;
                    tempPoly[j+1] = cy;
                    j = j+2;

                    break;
            case OUT:
                    incrside--;
                    break;
        }
    }

    sides = sides + incrside;

    for(i=0;i<sides*2;i=i+2)
    {
        poly[i] = tempPoly[i];
        poly[i+1] = tempPoly[i+1];
    }

    poly[i]   = poly[0];
    poly[i+1] = poly[1];
}

int main()
{
    int gdriver = DETECT,gmode;
    int i,j=0;
    int xx,yy;

    initgraph(&gdriver,&gmode,"c:\\tc\\bgi");

    cleardevice();

    printf("\nEnter no of sides : ");
    scanf("%d",&sides);

    for(i=0;i<sides;i++)
    {
        printf("\nEnter x , y : ");
        scanf("%d",&poly[j++]);
        scanf("%d",&poly[j++]);
    }
    poly[j++] = poly[0];
    poly[j] = poly[1];

    printf("\nEnter Clipwindow (Xmin,Ymin) - (Xmax,Ymax) : ");
    scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);

    cleardevice();

    setcolor(GREEN);
    drawpoly(sides+1,poly);

    rectangle(xmin,ymin,xmax,ymax);

    getch();

    leftClipper();
    rightClipper();
    bottomClipper();
    topClipper();

    setcolor(YELLOW);
    drawpoly(sides+1,poly);

    getch();
    return 1;
}

