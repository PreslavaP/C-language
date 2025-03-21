#include <stdio.h>

int main() {
    int length, current_length = 1, max_length = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &length);

    int numbers[length];
    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 1; i < length; i++) {
        if (numbers[i] > numbers[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_length = 1;
        }
    }

    if (current_length > max_length) {
        max_length = current_length;
    }

    printf("Length of the longest increasing subsequence: %d\n", max_length);

    return 0;
}
