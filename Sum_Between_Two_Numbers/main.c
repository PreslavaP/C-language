#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    int sum = 0;
    int start = 0;
    int end = 0;

    if (num1 < num2) {
        start = num1;
        end = num2;
    } else {
        start = num2;
        end = num1;
    }

    for(int i= start + 1; i < end; ++i)
    {
        sum += i;
    }

    printf("%d", sum);
    return 0;
}
