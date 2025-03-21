#include <stdio.h>
#include <stdlib.h>
//1. Напишете функция за размяна на две числа.
/*int swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    return x, y;
}*/

//2. Напишете функция, която проверява дали дадено число е четно или нечетно.
/*int even_or_odd(int num)
{
    if(num % 2 == 0)
    {
        return "The number is even!";
    }
    else
    {
        return "The number is odd!";
    }
}*/

//3. Напишете функция, която превръща от десетично в двоично едно число.
/*int decimal_to_binary(int num)
{
    int binary [32];
    int i = 0;

    if(num == 0)
    {
        printf("0");
        return;
    }

    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n");*/
}

int main()
{
   //1.
   /*int x, y;
   printf("Enter x and y: ");
   scanf("%d %d", &x, &y);

   swap(&x, &y);

   printf("After swap: x = %d, y = %d\n", x, y);
   return 0;*/

   //2.
   /*int num;
   printf("Enter number: ");
   scanf("%d", &num);

   printf(even_or_odd(num));
   return 0;*/

   //3.
   /*int num;
   printf("Enter number: ");
   scanf("%d", &num);

   printf("The decimal number %d in binary is: ", num);
   decimal_to_binary(num);
   return 0;*/
}
