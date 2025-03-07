#include <stdio.h>
#include <stdlib.h>

int smallerNum(int num1, int num2)
{
    if(num1!=0&&num2!=0)
    {
        if(num1<num2)
        {
            return num1;
        }
        else{
            return num2;
        }
    }
}

int biggerNum(int num1, int num2)
{
    if(num1>num2)
    {
        return num1;
    }
    else{
        return num2;
    }
}

int main()
{
    int num, min, max;
    int input = 1;

    printf("Enter numbers(to stop 0)\n");
    do
    {
        printf("Enter number: ");
        scanf("%d", &num);

         if (input) {
            min = max = num;
            input = 0;
        } else {
            min = smallerNum(min, num);
            max = biggerNum(max, num);
        }
    }while(num!=0);

    printf("Smallest number entered: %d\n", min);
    printf("Largest number entered: %d\n", max);
    return 0;
}
