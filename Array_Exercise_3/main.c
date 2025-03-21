#include <stdio.h>

int main() {
    int length;
    printf("Enter the number of elements: ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Reversed array: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
