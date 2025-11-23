#include <iostream>
#include <graphics.h>
using namespace std;

void directLine(int x1,int y1,int x2,int y2)
{
    if (x1 > x2) {    // fix loop logic
        swap(x1, x2);
        swap(y1, y2);
    }

    float m = (float)(y2 - y1) / (x2 - x1);
    float c = y1 - m * x1;

    for (int x = x1; x <= x2; x++) {
        int y = m * x + c;
        putpixel(x, y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    directLine(100, 100, 3, 200);  // now works

    getch();
    closegraph();
}

