#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void draw(int x[], int y[], int color){
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // ORIGINAL TRIANGLE
    int x[3] = {100, 200, 150};
    int y[3] = {100, 100, 50};

    draw(x, y, WHITE);
    outtextxy(50, 20, "Original Triangle");
    getch();


    // ---------------- TRANSLATION ----------------
    int tx = 100, ty = 80;
    for(int i=0;i<3;i++){
        x[i] += tx;
        y[i] += ty;
    }

    draw(x, y, YELLOW);
    outtextxy(50, 40, "Translated Triangle");
    getch();


    // ---------------- SCALING ----------------
    float sx = 1.5, sy = 1.5;
    for(int i=0;i<3;i++){
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }

    draw(x, y, GREEN);
    outtextxy(50, 60, "Scaled Triangle");
    getch();


    // ---------------- ROTATION ----------------
    float angle = 45;  // rotate 45 degrees
    float rad = angle * 3.14159 / 180;

    for(int i=0;i<3;i++){
        int xn = x[i]*cos(rad) - y[i]*sin(rad);
        int yn = x[i]*sin(rad) + y[i]*cos(rad);
        x[i] = xn;
        y[i] = yn;
    }

    draw(x, y, RED);
    outtextxy(50, 80, "Rotated Triangle");
    getch();


    closegraph();
    return 0;
}

