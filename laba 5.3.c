// Характеристикой строки целочисленной матрицы назовем сумму ее
// отрицательных четных элементов. Переставляя строки заданной матрицы,
// расположить их в соответствии с убыванием характеристик.

#include <stdio.h>
#include <string.h>

int main()
{
    int row, col;
    printf("Задайте количество строк матрицы: ");
    scanf("%d", &row);
    printf("Задайте количество столбцов матрицы: ");
    scanf("%d", &col);
    int i, j, a[row][col];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Введите элемент [%d,%d] матрицы: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    
    int sum[row];
    // find characteristics of each row in matrix
    for (i = 0; i < row; i++) {
        sum[i] = 0;
        for (j = 0; j < col; j++) {
            if (a[i][j] < 0) {
                if (a[i][j] % 2 == 0) {
                    sum[i] = sum[i] + a[i][j];
                }
            }
        }
    }
    int tempSum, tempA[col], max, maxIndex;
    // sorting the matrix of sum
    for (j = 0; j < row - 1; j++) {
        // find max in current row
        max = sum[j];
        // search max in current matrix
        for (i = j + 1; i < row; i++) {
            if (sum[i] > max) {
                max = sum[i];
                maxIndex = i;
            }
        }
        // replace the first row and max element of current matrix
        tempSum = max;
        memcpy(&tempA, &a[maxIndex], sizeof tempA);
        
        sum[maxIndex] = sum[j];
        memcpy(&a[maxIndex], &a[j], sizeof a[maxIndex]);
        
        sum[j] = tempSum;
        memcpy(&a[j], &tempA, sizeof a[j]);
    }
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Преобразованный элемент [%d,%d] матрицы: %d\n", i, j, a[i][j]);
        }
    }
}
