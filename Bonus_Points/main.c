#include <stdio.h>
#include <stdlib.h>

int main()
{
    int points;
    int final_points=0;
    int counter_ch=0;
    int counter_5=0;
    printf("Points: ");
    scanf("%d",&points);
    if(points>0&&points<100)
    {
            if(points%2==0){
                    final_points=points+6;
            }
            else if(points%10){
                final_points=points+7;
            }
            else
            {
        final_points=points+5;
        }
    }
    else if(points>100&&points<1000){
            if(points%2==0){
                    final_points=points+(points*0.2)+1;
            }
            else if(points%10){
                final_points=points+(points*0.2)+2;
            }
            else
            {
        final_points=points+(points*0.2);
            }
    }
    else if(points>1000){
             if(points%2==0){
                  final_points=points+(points*0.1)+1;
            }
            else if(points%10){
               final_points=points+(points*0.1)+2;
            }
            else
            {
      final_points=points+(points*0.1);
        }

    }
    printf("Final points: %d",final_points);
    return 0;
}
