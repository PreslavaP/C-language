#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    printf("Enter the number of rows (N): \n");
    scanf("%d", &N);
    printf("Enter the number of colums (M): \n");
    scanf("%d", &M);

    int matrix[N][M];
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("Number [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int minRow = 0, maxRow = 0;
    int minValue = matrix[0][0], maxValue = matrix[0][0];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
             if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRow = i;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        int temp = matrix[minRow][j];
        matrix[minRow][j] = matrix[maxRow][j];
        matrix[maxRow][j] = temp;
    }

    printf("\nNew Matrix after swapping rows:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
