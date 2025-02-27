#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, sum = 0;
    printf("Enter numbers (to stop the program enter 0).\n");

    while(1){
        scanf("%d", &num);
        if(num == 0){
            break;
        }

        sum += num;
    }

    printf("The sum of the numbers is: %d", sum);
    return 0;
}
