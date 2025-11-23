#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void drawTriangle(int x[], int y[], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}

void rotateTriangle(int x[], int y[], float angle) {
    float rad = angle * 3.14159 / 180;

    for (int i = 0; i < 3; i++) {
        int xn = x[i] * cos(rad) - y[i] * sin(rad);
        int yn = x[i] * sin(rad) + y[i] * cos(rad);

        x[i] = xn;
        y[i] = yn;
    }
}

void scaleTriangle(int x[], int y[], float sx, float sy) {
    for (int i = 0; i < 3; i++) {
        x[i] *= sx;
        y[i] *= sy;
    }
}

void translateTriangle(int x[], int y[], int tx, int ty) {
    for (int i = 0; i < 3; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Original triangle coordinates
    int x[3] = {100, 150, 50};
    int y[3] = {100, 200, 200};

    // Draw original triangle
    drawTriangle(x, y, WHITE);

    // ---------- APPLY TRANSFORMATIONS ----------
    // Example:
    rotateTriangle(x, y, 45);   // rotate 45 degrees
    scaleTriangle(x, y, 1.5, 1.5); // scale by 1.5
    translateTriangle(x, y, 200, 50); // move to the right
    
    // Draw transformed triangle
    drawTriangle(x, y, YELLOW);

    getch();
    closegraph();
    return 0;
}

