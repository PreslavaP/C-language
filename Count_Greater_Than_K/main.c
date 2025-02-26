#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    char input[20];

    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter K: ");
    scanf("%d", &K);

    int count = 0;

    for (int i = 0; i < N; ++i) {
        printf("Enter number %d (or 'Stop' to finish): ", i + 1);
        scanf("%s", input);

        if (strcmp(input, "Stop") == 0) {
            break;
        }

        int num = atoi(input);

        if (num > K && num % 3 == 0) {
            count++;
        }
    }

    printf("Count of numbers greater than %d and divisible by 3: %d\n", K, count);

    return 0;
}
