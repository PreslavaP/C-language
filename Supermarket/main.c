#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int code;
    char expiry[11];
    double price;
} Product;

// ===== Задача 2 =====
double avg_by_price(Product *products, int size, double limit_price) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (products[i].price > limit_price) {
            sum += products[i].price;
            count++;
        }
    }
    return count ? sum / count : 0.0;
}

// ===== Задача 3 =====
int write_text_file(Product *products, int size, const char *date, double min_price) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        perror("Error opening products.txt");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].expiry, date) < 0 && products[i].price > min_price) {
            fprintf(file, "%s-%d-%s-%.2lfлв\n", products[i].name, products[i].code,
                    products[i].expiry, products[i].price);
            count++;
        }
    }

    fclose(file);
    return count;
}

// ===== Задача 4 =====
void print_info(const char *product_name, int product_code) {
    FILE *fp = fopen("products.bin", "rb");
    if (fp == NULL) {
        perror("Error opening binary file");
        return;
    }

    Product temp;
    int found = 0;

    while (fread(&temp, sizeof(Product), 1, fp)) {
        if (strcmp(temp.name, product_name) == 0 && temp.code == product_code) {
            printf("Product info: %s - use before %s - price %.2lf lv\n",
                   temp.name, temp.expiry, temp.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product \"%s\" with code %d not found in products.bin\n", product_name, product_code);
    }

    fclose(fp);
}

int main() {
    int n;
    do {
        printf("Enter number of products (between 11 and 29): ");
        scanf("%d", &n);
    } while (n < 11 || n > 29);

    Product *products = (Product *)malloc(n * sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", products[i].name);
        printf("Code: ");
        scanf("%d", &products[i].code);
        printf("Expiry date (YYYY.MM.DD): ");
        scanf(" %10s", products[i].expiry);
        printf("Price: ");
        scanf("%lf", &products[i].price);
    }

    // --- ЗАДАЧА 2: Средна цена над лимит ---
    double limit_price;
    printf("\nEnter price limit to calculate average: ");
    scanf("%lf", &limit_price);
    double avg = avg_by_price(products, n, limit_price);
    printf("Average price of products over %.2lf: %.2lf lv\n", limit_price, avg);

    // --- ЗАДАЧА 3: Запис във файл при филтър ---
    char filter_date[11];
    double filter_price;
    printf("\nFilter products to write to file (enter date and min price):\n");
    printf("Date (YYYY.MM.DD): ");
    scanf("%s", filter_date);
    printf("Min price: ");
    scanf("%lf", &filter_price);

    int written = write_text_file(products, n, filter_date, filter_price);
    printf("Written %d products to products.txt\n", written);

    // --- ЗАДАЧА 4: Създаване на бинарен файл и търсене ---
    FILE *bin = fopen("products.bin", "wb");
    if (bin != NULL) {
        fwrite(products, sizeof(Product), n, bin);
        fclose(bin);
    }

    char search_name[50];
    int search_code;
    printf("\nSearch for product in binary file\nName: ");
    scanf(" %[^\n]", search_name);
    printf("Code: ");
    scanf("%d", &search_code);
    print_info(search_name, search_code);

    free(products);

    return 0;
}
