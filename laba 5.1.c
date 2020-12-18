#include <stdio.h>
void main() {
    int i, ii, j;
    unsigned short m = 10, n = 12;
    float a[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Введите элемент [%d,%d] массива: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    
    unsigned short hasPoints = 0;
    int maxRow, maxRowIndex, maxColumnIndex,
        minRow, minRowIndex, minColumnIndex
    ;
    unsigned short isNotTrueMinPoint, isNotTrueMaxPoint;
    // check each row to find min and max
    for (i = 0; i < m; i++) {
        maxRow = a[i][0];
        maxRowIndex = i;
        maxColumnIndex = 0;
        
        minRow = a[i][0];
        minRowIndex = i;
        minColumnIndex = 0;
        // determinate max and min elements and indexes in row
        for (j = 1; j < n; j++) {
            // find max element in row
            if (a[i][j] > maxRow) {
                maxRow = a[i][j];
                maxRowIndex = i;
                maxColumnIndex = j;
            }
            // find min element in row
            if (a[i][j] < minRow) {
                minRow = a[i][j];
                minRowIndex = i;
                minColumnIndex = j;
            }
        }
        // check column: our points are true?
        isNotTrueMinPoint = 0;
        isNotTrueMaxPoint = 0;
        for (ii = 0; ii < m; ii++) {
            if (!isNotTrueMaxPoint && a[ii][maxColumnIndex] < maxRow) {
                isNotTrueMaxPoint = 1;
            }
            if (!isNotTrueMinPoint && a[ii][minColumnIndex] > minRow) {
                isNotTrueMinPoint = 1;
            }
            if (isNotTrueMinPoint && isNotTrueMaxPoint) {
                break;
            }
        }
        if (!isNotTrueMaxPoint) {
            // save this point as true point
            printf("[%d,%d]\n", maxRowIndex, maxColumnIndex);
            hasPoints = 1;
        }
        if (!isNotTrueMinPoint) {
            // save this point as true point
            printf("[%d,%d]\n", minRowIndex, minColumnIndex);
            hasPoints = 1;
        }
    }
    if (!hasPoints) {
        printf("Седловых точек в указанном массиве нет");
    }
}
