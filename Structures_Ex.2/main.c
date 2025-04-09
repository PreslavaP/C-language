#include <stdio.h>
#include <string.h>

struct SpecializedVehicle {
    char brand[50];
    char model[50];
    int year;
    float max_speed;
    char type[30];
    int engine_capacity;
    float weight;
};

void add_vehicle(struct SpecializedVehicle* vehicle) {
    printf("\nEnter details of the new vehicle:\n");
    printf("Enter brand: ");
    scanf("%s", vehicle->brand);
    printf("Enter model: ");
    scanf("%s", vehicle->model);
    printf("Enter year: ");
    scanf("%d", &vehicle->year);
    printf("Enter max speed (km/h): ");
    scanf("%f", &vehicle->max_speed);
    printf("Enter type (Car, Motorcycle, Boat, Airplane): ");
    scanf("%s", vehicle->type);

    if (strcmp(vehicle->type, "Car") == 0 || strcmp(vehicle->type, "Motorcycle") == 0) {
        printf("Enter engine capacity (cc): ");
        scanf("%d", &vehicle->engine_capacity);
    } else {
        printf("Enter weight (kg): ");
        scanf("%f", &vehicle->weight);
    }
}

int main() {
    struct SpecializedVehicle vehicles[7] = {
        {"BMW", "E39 530d", 2000, 230.0, "Car", 3000, 1500.0},
        {"Harley-Davidson", "Sportster 1200", 2019, 190.0, "Motorcycle", 1200, 300.0},
        {"Yamaha", "YZF-R1", 2022, 300.0, "Motorcycle", 1000, 200.0},
        {"Yamaha", "242X", 2021, 80.0, "Boat", 0, 2000.0},
        {"Boeing", "737-800", 2018, 850.0, "Airplane", 0, 80000.0},
        {"Audi", "A8 3.0 TDI", 2017, 250.0, "Car", 3000, 1800.0}
    };

    struct SpecializedVehicle new_vehicle;

    add_vehicle(&new_vehicle);
    vehicles[6] = new_vehicle;

    for (int i = 0; i < 7; i++) {
        printf("\nVehicle %d:\n", i + 1);
        printf("Brand: %s\n", vehicles[i].brand);
        printf("Model: %s\n", vehicles[i].model);
        printf("Year: %d\n", vehicles[i].year);
        printf("Max Speed: %.2f km/h\n", vehicles[i].max_speed);
        printf("Type: %s\n", vehicles[i].type);
        if (strcmp(vehicles[i].type, "Car") == 0 || strcmp(vehicles[i].type, "Motorcycle") == 0) {
            printf("Engine Capacity: %d cc\n", vehicles[i].engine_capacity);
        } else {
            printf("Weight: %.2f kg\n", vehicles[i].weight);
        }
    }

    int fastest_vehicle = 0;
    for (int i = 1; i < 7; i++) {
        if (vehicles[i].max_speed > vehicles[fastest_vehicle].max_speed) {
            fastest_vehicle = i;
        }
    }

    printf("\nThe fastest vehicle is:\n");
    printf("Brand: %s\n", vehicles[fastest_vehicle].brand);
    printf("Model: %s\n", vehicles[fastest_vehicle].model);
    printf("Max Speed: %.2f km/h\n", vehicles[fastest_vehicle].max_speed);

    return 0;
}
