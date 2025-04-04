#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter NxN elements for the array: ");
    scanf("%d",&number);

    int matrix[number][number];
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix: \n");
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("Main diagonal elements: \n");
    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
            if(i==j){
                printf("%d ", matrix[i][i]);
            }
            else{
                printf("");
            }
        }
    }
    printf("\n");

    printf("Secondary diagonal elements: \n");
    for (int i = 0; i < number; i++) {
        printf("%d ", matrix[i][number - 1 - i]);
    }
    printf("\n");

    printf("Elements over the main diagonal: \n");
    for (int i = 0; i < number; i++) {
        for (int j = i + 1; j < number; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    printf("Elements under the main diagonal: \n");
    for (int i = 1; i < number; i++) {
        for (int j =0; j < i; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}
