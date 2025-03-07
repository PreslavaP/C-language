#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, transport;
    float price = 0;
    char type;

    printf("Enter km: ");
    scanf("%d", &n);

    printf("Choose transport 1/2/3: ");
    scanf("%d", &transport);

    if (n < 20 && transport == 2) {
        transport = 1;
    }

    while (n >= 20 && n < 100 && transport == 3) {
        printf("Choose new transport 1/2: ");
        scanf("%d", &transport);
    }

    getchar();

    printf("Enter type d/n: ");
    scanf("%c", &type);

    switch (transport) {
        case 1:
            if (type == 'd') {
                price = 0.7 + (0.79 * n);
            } else {
                price = 0.7 + (0.9 * n);
            }
            break;
        case 2:
            price = 0.09 * n;
            break;
        case 3:
            if (type == 'd') {
                price = 0.06 * n;
            } else {
                price = 0.7 + (0.9 * n);
            }
            break;
        default:
            printf("Invalid transport choice\n");
            return 1;
    }

    printf("The price is: %.2f\n", price);

    return 0;
}
