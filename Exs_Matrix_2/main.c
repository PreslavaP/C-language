#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    int sum=0;
    int result=0;
    int maxSum=-10;

    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);

     int matrix[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter numbers: ");
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        sum += matrix[ni][nj];
                    }
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                result = matrix[i][j];
            }
        }
    }

    printf("Sum result: %d\n", result);


    return 0;
}
