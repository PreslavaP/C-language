#include <stdio.h>
#include <stdlib.h>

int AreaSquare(int a){
    int area=a*a;
    printf("AREA: %d",area);
}
int AreaRectangle(int a, int b){
    int area=a*b;
    printf("AREA: %d",area);
}
int AreaSquareSquare(int a,int b){
    int area=2*(a+b);
     printf("AREA: %d",area);
}
int AreaCircle(int r){
    int area=2*3.14*r;
    printf("AREA: %d",area);
}

int main()
{
    int n,a,b,p;
    printf("Enter number 1/2/3/4: ");
    scanf("%d",&n);
    switch(n){
case 1:
     printf("Enter a: ");
    scanf("%d",&a);
    AreaSquare(a);
    break;
case 2:
     printf("Enter a: ");
    scanf("%d",&a);
     printf("Enter b: ");
    scanf("%d",&b);
    AreaRectangle(a,b);
    break;
case 3:
      printf("Enter a: ");
    scanf("%d",&a);
     printf("Enter b: ");
    scanf("%d",&b);
    AreaSquareSquare(a,b);
    break;
case 4:
     printf("Enter p: ");
    scanf("%d",&p);
    AreaCircle(p);
    break;
    }

}
