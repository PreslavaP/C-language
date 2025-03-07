#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hours, minutes;

    printf("Enter hours: ");
    scanf("%d", &hours);
    printf("Enter minutes: ");
    scanf("%d", &minutes);

    if(hours<0&&hours>23)
    {
        printf("Enter correct hours: ");
        scanf("%d", &hours);
    }
    if(minutes<0&&minutes>59)
    {
        printf("Enter correct minutes: ");
        scanf("%d", &minutes);
    }

    minutes += 15;

    if(minutes>=60){
        minutes-=60;
        hours++;

        if(hours==24)
        {
            hours=0;
        }
    }

    printf("Time after 15 minutes is: %d:%02d", hours, minutes);
    return 0;
}
