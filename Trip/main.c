#include <stdio.h>

int main() {
    int n;
    char period;

    double taxi_start_fee = 0.70, taxi_day_rate = 0.79, taxi_night_rate = 0.90;
    double bus_rate = 0.09, train_rate = 0.06;

    printf("Enter the distance (in kilometers): ");
    scanf("%d", &n);
    printf("Enter the period (D for day, N for night): ");
    getchar();
    scanf("%c", &period);

    double cheapest_price = 1000000.0;

    double taxi_price;
    if (period == 'D') {
        taxi_price = taxi_start_fee + taxi_day_rate * n;
    } else {
        taxi_price = taxi_start_fee + taxi_night_rate * n;
    }
    if (taxi_price < cheapest_price) {
        cheapest_price = taxi_price;
    }

    if (n >= 20) {
        double bus_price = bus_rate * n;
        if (bus_price < cheapest_price) {
            cheapest_price = bus_price;
        }
    }

    if (n >= 100) {
        double train_price = train_rate * n;
        if (train_price < cheapest_price) {
            cheapest_price = train_price;
        }
    }

    printf("The cheapest transport will cost: %.2f BGN.\n", cheapest_price);

    return 0;
}
