#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    int even_sum = 0;
    int odd_product = 1;
    int start = 0;
    int end = 0;

    if (num1 < num2) {
        start = num1;
        end = num2;
    } else {
        start = num2;
        end = num1;
    }

    for(int i = start + 1; i < end; ++i){
        if(i%2 == 0){
            even_sum+=i;
        } else{
            odd_product = odd_product * i;
        }
    }

    printf("The sum of even numbers is: %d\n", even_sum);
    printf("The product of odd numbers is: %d", odd_product);
    return 0;
}
