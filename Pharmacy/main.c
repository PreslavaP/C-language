#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[31];
    char expiry_date[9];
    long long code;
    double price;
    int quantity;
} Medicine;

Medicine* load_medicines(const char* filename, int* count) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        *count = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size % sizeof(Medicine) != 0) {
        fprintf(stderr, "Invalid file format.\n");
        fclose(file);
        *count = 0;
        return NULL;
    }

    *count = file_size / sizeof(Medicine);
    Medicine* medicines = (Medicine*) malloc(file_size);

    if (!medicines) {
        perror("Memory allocation failed");
        fclose(file);
        *count = 0;
        return NULL;
    }

    size_t read_items = fread(medicines, sizeof(Medicine), *count, file);
    if (read_items != *count) {
        perror("Error reading from file");
        free(medicines);
        fclose(file);
        *count = 0;
        return NULL;
    }

    fclose(file);
    return medicines;
}

int is_expired_before(const char* date1, const char* date2) {
    int month1, year1, month2, year2;
    sscanf(date1, "%2d.%4d", &month1, &year1);
    sscanf(date2, "%2d.%4d", &month2, &year2);

    if (year1 < year2) return 1;
    if (year1 == year2 && month1 < month2) return 1;
    return 0;
}

Medicine* get_expired_medicines(Medicine* medicines, int count, const char* ref_date, int* expired_count) {
    *expired_count = 0;

    for (int i = 0; i < count; i++) {
        if (is_expired_before(medicines[i].expiry_date, ref_date)) {
            (*expired_count)++;
        }
    }

    if (*expired_count == 0) {
        return NULL;
    }

    Medicine* result = (Medicine*)malloc((*expired_count) * sizeof(Medicine));
    if (!result) {
        perror("Memory allocation failed");
        *expired_count = 0;
        return NULL;
    }

    int idx = 0;
    for (int i = 0; i < count; i++) {
        if (is_expired_before(medicines[i].expiry_date, ref_date)) {
            result[idx++] = medicines[i];
        }
    }

    return result;
}

int write_offers_to_file(Medicine* medicines, int count, double min_price, double max_price) {
    FILE* file = fopen("offer.txt", "w");
    if (!file) {
        perror("Failed to open offer.txt for writing");
        return 0;
    }

    int written = 0;

    for (int i = 0; i < count; i++) {
        if (medicines[i].price >= min_price && medicines[i].price <= max_price) {
            fprintf(file, "%s\n", medicines[i].name);
            fprintf(file, "%s\n", medicines[i].expiry_date);
            fprintf(file, "%lld\n", medicines[i].code);
            fprintf(file, "%.2lf leva\n", medicines[i].price);
            written++;
        }
    }

    fclose(file);
    return written;
}

void delete_medicine(Medicine** medicines, int* count, const char* target_name, const char* target_date) {
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (strcmp((*medicines)[i].name, target_name) == 0 &&
            strcmp((*medicines)[i].expiry_date, target_date) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine with name \"%s\" and expiry date \"%s\" not found.\n", target_name, target_date);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        (*medicines)[i] = (*medicines)[i + 1];
    }

    Medicine* resized = realloc(*medicines, (*count - 1) * sizeof(Medicine));
    if (resized || *count - 1 == 0) {
            *medicines = resized;
    }

    (*count)--;
    printf("Medicine \"%s\" with expiry \"%s\" has been deleted.\n", target_name, target_date);
}

int main() {
    int count = 0;
    Medicine* medicines = load_medicines("medicines.bin", &count);
    if (!medicines) return 1;

    printf("Loaded %d medicines from file.\n\n", count);

    const char* reference_date = "05.2025";
    int expired_count = 0;
    Medicine* expired = get_expired_medicines(medicines, count, reference_date, &expired_count);

    if (expired) {
        printf("Medicines expiring before %s:\n", reference_date);
        for (int i = 0; i < expired_count; i++) {
            printf("- %s (Expires: %s)\n", expired[i].name, expired[i].expiry_date);
        }
        free(expired);
    } else {
        printf("No medicines expiring before %s.\n", reference_date);
    }

    double min_price = 5.00, max_price = 20.00;
    int written = write_offers_to_file(medicines, count, min_price, max_price);
    if (written > 0) {
        printf("\nWrote %d medicines to offer.txt (price between %.2f and %.2f).\n", written, min_price, max_price);
    } else {
        printf("\nNo medicines found in the given price range.\n");
    }

    const char* name_to_delete = "Paracetamol";
    const char* expiry_to_delete = "06.2025";
    delete_medicine(&medicines, &count, name_to_delete, expiry_to_delete);

    printf("\nRemaining medicines:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Expiry: %s, Price: %.2lf\n",
               medicines[i].name, medicines[i].expiry_date, medicines[i].price);
    }

    free(medicines);
    return 0;
}
/*

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[31];
    char expiry_date[9];
    long long code;
    double price;
    int quantity;
} Medicine;

int main() {
    Medicine sample_meds[] = {
        {"Paracetamol", "06.2025", 1234567890123, 7.50, 100},
        {"Ibuprofen", "04.2025", 2345678901234, 12.99, 80},
        {"Aspirin", "12.2024", 3456789012345, 5.49, 50},
        {"Vitamin C", "09.2025", 4567890123456, 9.99, 150}
    };

    FILE* file = fopen("medicines.bin", "wb");
    if (!file) {
        perror("Failed to create medicines.bin");
        return 1;
    }

    size_t written = fwrite(sample_meds, sizeof(Medicine), 4, file);
    if (written != 4) {
        perror("Failed to write all data");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Sample medicines.bin file created successfully.\n");
    return 0;
}*/
