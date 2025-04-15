#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void count_digits(int num, int *even_count, int *odd_count) {
    num = abs(num);
    if (num == 0) {
        (*even_count)++;
        return;
    }
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0)
            (*even_count)++;
        else
            (*odd_count)++;
        num /= 10;
    }
}

int main() {
    FILE *fp = fopen("numbers2.bin", "wb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    int num;
    char choice;
    int total_count = 0;

    do {
        printf("Enter number: ");
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, fp);
        total_count++;

        printf("Add another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    fclose(fp);
    printf("File created successfully.\n");

    fp = fopen("numbers2.bin", "rb");
    if (!fp) {
        perror("Error reading file");
        return 1;
    }

    int *arr = malloc(total_count * sizeof(int));
    if (!arr) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    fread(arr, sizeof(int), total_count, fp);
    fclose(fp);

    int even_count = 0, odd_count = 0;
    for (int i = 0; i < total_count; i++) {
        count_digits(arr[i], &even_count, &odd_count);
    }

    qsort(arr, total_count, sizeof(int), compare);

    FILE *out = fopen("sorted2.txt", "w");
    if (!out) {
        perror("Error opening output file");
        free(arr);
        return 1;
    }

    fprintf(out, "Sorted array:\n");
    for (int i = 0; i < total_count; i++) {
        fprintf(out, "%d\n", arr[i]);
    }

    fclose(out);
    free(arr);

    printf("Sorted array written to sorted2.txt successfully.\n");
    printf("\nTotal even digits: %d\n", even_count);
    printf("Total odd digits: %d\n", odd_count);

    return 0;
}
