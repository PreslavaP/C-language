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
    printf("Matrix:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int isRowSorted = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                isRowSorted = 0;
                break;
            }
        }
        if (!isRowSorted) break;
    }

    int isColSorted = 1;
    for(int j = 0; j < M; j++){
        for(int i = 0; i < N - 1; i++){
            if (matrix[i][j] < matrix[i + 1][j]) {
                isColSorted = 0;
                break;
            }
        }
        if(!isColSorted) break;
    }

    if (isRowSorted && isColSorted) {
        printf("The matrix is sorted by rows (ascending) and by columns (descending).\n");
    } else {
        printf("The matrix is NOT sorted as required.\n");
    }

    return 0;
}
