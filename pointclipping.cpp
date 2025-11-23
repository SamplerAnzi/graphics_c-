#include <iostream>
#include <graphics.h>
using namespace std;

void pointClipping(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    // Check if the point lies inside the clipping window
    if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) {
        cout << "Point (" << x << "," << y << ") is INSIDE the window.\n";
        putpixel(x, y, WHITE); // draw point
    } 
    else {
        cout << "Point (" << x << "," << y << ") is OUTSIDE the window.\n";
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Clipping window boundary
    int xmin = 100, ymin = 100;
    int xmax = 300, ymax = 300;

    // Draw clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Test point
    int x = 150, y = 250;  // change values to test

    pointClipping(x, y, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}

