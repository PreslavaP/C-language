#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1==num2 && num1 == num3)
    {
        printf("YES!");
    }
    else
    {
        printf("NO!");
    }
}
