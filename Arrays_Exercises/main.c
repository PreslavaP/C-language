#include <stdio.h>

int main() {
    int length;

    printf("Enter the number of items : ");
    scanf("%d", &length);

    int numbers[length];

    printf("Enter items: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &numbers[i]);
    }

    int max_start = 0, max_length = 1;
    int current_start = 0, current_length = 1;

    for (int i = 1; i < length; i++) {
        if (numbers[i] == numbers[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                max_start = current_start;
            }
            current_start = i;
            current_length = 1;
        }
    }

    if (current_length > max_length) {
        max_length = current_length;
        max_start = current_start;
    }

    printf("The longest platform is: ");
    for (int i = max_start; i < max_start + max_length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\nThe length of this platform is: %d\n", max_length);

    return 0;
}
