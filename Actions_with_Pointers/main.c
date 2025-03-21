#include <stdio.h>

int calculate(int *a, int *b, int *sum, int *sub, int *abs, float *div)
{
    *sum = *a + *b;
    *sub = *a - *b;
    *abs = (*a) * (*b);
    if (*b != 0) {
        *div = (float)(*a) / (*b);
    } else {
        printf("Division by zero!\n");
        *div = 0;
    }
    return 0;
}

int main()
{
    int num1, num2, sum, sub, abs;
    float div;

    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    calculate(&num1, &num2, &sum, &sub, &abs, &div);

    printf("SUM: %d\n", sum);
    printf("SUB: %d\n", sub);
    printf("MUL: %d\n", abs);
    printf("DIV: %.2f\n", div);

    return 0;
}
