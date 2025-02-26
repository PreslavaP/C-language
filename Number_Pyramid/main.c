#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    int count;
    for (int i = 1; i <= number; ++i) {

        for (int j = 1; j <= i; ++j) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
