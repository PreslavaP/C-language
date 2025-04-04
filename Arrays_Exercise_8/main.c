#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter NxN elements for the square: ");
    scanf("%d",&number);

    int matrix[number][number];
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The Square: \n");
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sumd1 = 0, sumd2=0;
    for (int i = 0; i < number; i++)
    {
        sumd1 += matrix[i][i];
        sumd2 += matrix[i][number-1-i];
    }
    if(sumd1!=sumd2)
    {
        printf("It's not magic square");
    }
    int rowSum = 0, colSum = 0;
    for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++){
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
        }
        if (rowSum != colSum || colSum != sumd1){
            printf("It's not magic square.");
            return 1;
        }
        else{
            printf("It's magic square");
            return 1;
        }
     }
    return 0;
}
