#include <stdio.h>

int main() {
    double V, P1, P2, N;

    printf("Enter pool capacity (V in liters): ");
    scanf("%lf", &V);

    printf("Enter flow rate of pipe 1 (liters per hour): ");
    scanf("%lf", &P1);

    printf("Enter flow rate of pipe 2 (liters per hour): ");
    scanf("%lf", &P2);

    printf("Enter the number of hours the worker is away (N): ");
    scanf("%lf", &N);

    double totalWater = (P1 + P2) * N;

    if (totalWater <= V) {
        printf("The pool is full.");
    } else {
        double overflow = totalWater - V;
        printf("For %.2f hours, the pool overflows with %.2f liters.\n", N, overflow);
    }

    return 0;
}
