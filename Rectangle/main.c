#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,x,y1,y2,y;
    printf("Enter x1, x2, x, y1, y2, y\n");
    scanf("%d %d %d %d %d %d",&x1,&x2,&x,&y1,&y2,&y);
    while(x1>x2){
        printf("Enter new number for x1: ");
        scanf("%d",&x1);
    }
    while(y1>y2){
        printf("Enter new number for y1: ");
        scanf("%d",&y1);
    }
     if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Inside\n");
    } else {
        printf("Outside\n");
    }
    return 0;
}
