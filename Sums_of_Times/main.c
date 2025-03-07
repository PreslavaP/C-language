#include <stdio.h>
#include <stdlib.h>

int main()
{
    int run1,  run2, run3;
    printf("Enter the time of the three runners: ");
    scanf("%d %d %d", &run1, &run2, &run3);

    int sum = run1 + run2 + run3;
    int minutes, seconds;

    minutes = sum / 60;
    seconds = sum % 60;

    printf("The time is: %d:%02d", minutes, seconds);
    return 0;
}
