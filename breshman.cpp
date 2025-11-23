#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
void breshman(int x1,int y1,int x2,int y2){
    int dx=abs(x2-x1),dy=abs(y2-y1);
    bool ymajor=dy>dx;
    if(ymajor){
        swap(dx,dy);
    }
    int d=2*dy-dx;
    int x=x1,y=y1;
    // putpixel(round(x),round(y),WHITE);
    for(int  i=0;i<=dx;i++){
        if(d<0){
            x+=1;
            d+=2*dy;
        }
        else{
            x+=1;
            y+=1;
            d+=2*(dy-dx);
        }
        putpixel(round(x),round(y),WHITE);
        delay(10);
    }
}
int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\TURBOC3\BGI");
    breshman(100,100,500,500);
    getch();
    closegraph();
}
