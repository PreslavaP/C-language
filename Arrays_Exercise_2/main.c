#include <stdio.h>

int main() {
    int len;
    printf("Enter the number of elements: ");
    scanf("%d", &len);

    int arr[len];
    printf("Enter the elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    int is_valid = 1;

    for (int i = 1; i < len; i++) {
        if ((i % 2 == 1 && arr[i] <= arr[i - 1]) || (i % 2 == 0 && arr[i] >= arr[i - 1])) {
            is_valid = 0;
            break;
        }
    }

    if (is_valid) {
        printf("All conditions are met.\n");
    } else {
        printf("Conditions are not met.\n");
    }

    return 0;
}
