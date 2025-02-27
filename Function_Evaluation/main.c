#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2;
    printf("Enter two numbers for range(divided by space): ");
    scanf("%f %f", &num1, &num2);

    for(float i=num1; i<=num2; i+=0.01){
        float f = i * i - 4;
        printf("f(%.2f) = %.2f\n", i, f);
    }
    return 0;
}
