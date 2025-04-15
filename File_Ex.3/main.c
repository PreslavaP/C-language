#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brand[20];
    char model[6];
    int cc;
    float price;
    char registration;
} CarDealership;

void add_car() {
    FILE *binFile = fopen("cars.bin", "ab");
    FILE *txtFile = fopen("cars.txt", "a");

    if (!binFile || !txtFile) {
        perror("Error opening files");
        return;
    }

    CarDealership car;

    printf("\n--- Add New Car ---\n");

    printf("Enter brand: ");
    scanf(" %19s", car.brand);

    printf("Enter model (5 characters): ");
    scanf("%s", car.model);

    printf("Enter engine volume (cc): ");
    scanf("%d", &car.cc);

    printf("Enter price: ");
    scanf("%f", &car.price);

    printf("Is the car registered? (Y/N): ");
    scanf(" %c", &car.registration);

    fwrite(&car, sizeof(CarDealership), 1, binFile);

    fprintf(txtFile, "%s\n%s\n%d\n%.2f\n%c\n",
            car.brand, car.model, car.cc, car.price, car.registration);

    fclose(binFile);
    fclose(txtFile);

    printf("Car added successfully!\n");
}

void display_data() {
    FILE *binFile = fopen("cars.bin", "rb");
    FILE *txtFile = fopen("cars.txt", "r");

    if (!binFile || !txtFile) {
        perror("Error opening files for reading");
        return;
    }

    CarDealership car;
    int count = 1;

    printf("\n--- Binary File Contents (cars.bin) ---\n");
    while (fread(&car, sizeof(CarDealership), 1, binFile)) {
        printf("Car #%d:\n", count++);
        printf("Brand: %s\n", car.brand);
        printf("Model: %s\n", car.model);
        printf("Engine (cc): %d\n", car.cc);
        printf("Price: %.2f\n", car.price);
        printf("Registered: %c\n", car.registration);
        printf("-----------------------------\n");
    }

    rewind(txtFile);
    char line[100];
    count = 1;

    printf("\n--- Text File Contents (cars.txt) ---\n");
    while (fgets(line, sizeof(line), txtFile)) {
        printf("Line %d: %s", count++, line);
    }

    fclose(binFile);
    fclose(txtFile);
}

int main() {
    FILE *binClear = fopen("cars.bin", "wb");
    FILE *txtClear = fopen("cars.txt", "w");

    if (binClear) fclose(binClear);
    if (txtClear) fclose(txtClear);

    int choice;

    do {
        printf("\n=== Car Dealership Menu ===\n");
        printf("1. Add new car\n");
        printf("2. Display all data (binary and text)\n");
        printf("0. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_car();
                break;
            case 2:
                display_data();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
