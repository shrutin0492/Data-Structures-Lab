#include <stdio.h>

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Structure to represent a rectangle
struct Rectangle {
    struct Point upperLeft;
    struct Point lowerRight;
};

// Function to calculate the area of a rectangle
int calculateArea(struct Rectangle r) {
    int width = r.lowerRight.x - r.upperLeft.x;
    int height = r.lowerRight.y - r.upperLeft.y;
    return width * height;
}

int main() {
    struct Rectangle rect;

    printf("Enter the coordinates of the upper left point (x y): ");
    scanf("%d %d", &rect.upperLeft.x, &rect.upperLeft.y);

    printf("Enter the coordinates of the lower right point (x y): ");
    scanf("%d %d", &rect.lowerRight.x, &rect.lowerRight.y);

    int area = calculateArea(rect);
    printf("Area of the rectangle: %d\n", area);

    return 0;
}
