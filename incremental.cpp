#include <iostream>
#include <graphics.h>
using namespace std;

void incrementalLine(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float m = dy / dx;   // slope

    float y = y1;

    for (int x = x1; x <= x2; x++) {
        putpixel(x, int(y + 0.5), WHITE); // rounding
        y = y + m; // incremental update
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\TURBOC3\BGI");
    incrementalLine(100, 100, 300, 300);
    getch();
    closegraph();
}
