#include <stdio.h>

int main() {
    int len, k;
    printf("Enter the number of elements: ");
    scanf("%d", &len);

    int arr[len], temp[len];
    printf("Enter elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to offset: ");
    scanf("%d", &k);
    k = k % len;

    for (int i = 0; i < len; i++) {
        temp[(i + k) % len] = arr[i];
    }
    for (int i = 0; i < len; i++) {
        arr[i] = temp[i];
    }
    printf("Offset array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
