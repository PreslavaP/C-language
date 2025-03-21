#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int length, K;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    int arr[length];

    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &K);

    sortDescending(arr, length);

    if (K > 0 && K <= length) {
        printf("The %d-th largest element is: %d\n", K, arr[K - 1]);
    } else {
        printf("Invalid value for K!\n");
    }

    return 0;
}
