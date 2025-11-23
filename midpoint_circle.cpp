#include<iostream>
#include<graphics.h>

void midPointCircle(int xc,int yc,int r){
    int x=0,y=r,p=1-r;
    while(x<=y){
        putpixel(xc+x,yc+y,WHITE); putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE); putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE); putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE); putpixel(xc-y,yc-x,WHITE);
        x++;
        if(p<0)p+=2*x+1;
        else{ y--; p+=2*(x-y)+1; }
    }
}

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    midPointCircle(200,200,100);
    getch(); closegraph();
}
