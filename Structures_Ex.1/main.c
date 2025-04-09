#include <stdio.h>
#include <stdlib.h>

struct Point {
    float x, y, z;
};

float distance(struct Point a, struct Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y) +
                (a.z - b.z)*(a.z - b.z));
}

int main()
{
    struct Point points[3];

    printf("Enter coordinates for point A (x y z): ");
    scanf("%f %f %f", &points[0].x, &points[0].y, &points[0].z);

    printf("Enter coordinates for point B (x y z): ");
    scanf("%f %f %f", &points[1].x, &points[1].y, &points[1].z);

    printf("Enter coordinates for point C (x y z): ");
    scanf("%f %f %f", &points[2].x, &points[2].y, &points[2].z);

    float ab = distance(points[0], points[1]);
    float bc = distance(points[1], points[2]);
    float ca = distance(points[2], points[0]);

    printf("\nSides of the triangle:\n");
    printf("AB = %.2f\n", ab);
    printf("BC = %.2f\n", bc);
    printf("CA = %.2f\n", ca);

    return 0;
}
