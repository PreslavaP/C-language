#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n, even_count = 0, odd_count = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    FILE *fp = fopen("numbers.bin", "wb");
    if (!fp) {
        perror("Error opening file for writing");
        return 1;
    }

    fwrite(&n, sizeof(int), 1, fp);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, fp);

        if(i % 2 == 0){
            even_count++;
        }else{
            odd_count++;
        }
    }

    fclose(fp);
    printf("Binary file created successfully.\n");

    fp = fopen("numbers.bin", "rb");
    if (!fp) {
        perror("Error opening file for reading");
        return 1;
    }

    fread(&n, sizeof(int), 1, fp);

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    fread(arr, sizeof(int), n, fp);
    fclose(fp);

    qsort(arr, n, sizeof(int), compare);

    FILE *out = fopen("sorted.txt", "w");
    if (!out) {
        perror("Error opening output file");
        free(arr);
        return 1;
    }

    fprintf(out, "Sorted array:\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d\n", arr[i]);
    }

    fclose(out);
    free(arr);

    printf("Sorted array written to sorted.txt successfully.\n");

    printf("\nThe amount of even numbers is: %d\n", even_count);
    printf("The amount of odd numbers is: %d\n", odd_count);

    return 0;
}
