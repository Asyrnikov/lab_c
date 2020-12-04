// 2. Элемент матрицы назовем седловой точкой, если он наименьший в своей строке и
// наибольший (одновременно) в своем столбце (или наоборот, наибольший в своей строке и
// наименьший в своем столбце). Для заданной целой матрицы размером 10 x 12 напечатать
// индексы всех ее седловых точек.

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void main() {
    // define matrix row/column sizes
    unsigned short m = 3, n = 4;
    
    // Allocate memory for matrix
    int ** a = malloc(m*sizeof(int*) + m*n*sizeof(int));
    int * pc = (int*) a;
    // pointer to the first element of matrix
    pc += m*sizeof(int*);
    
    // fill in array of pointers to data arrays
    int i;
    for (i = 0; i < m; i++) {
        a[i] = pc + i*sizeof(n*sizeof(int));
    }
    // ask user to enter values of matrix elements
    int j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Введите элемент [%d,%d] массива: ", i, j);
            scanf("%d", *(a+i)+j);
        }
    }
    
    unsigned short hasPoints = 0;
    int maxRow, maxRowIndex, maxColumnIndex,
        minRow, minRowIndex, minColumnIndex
    ;
    unsigned short isNotTrueMinPoint, isNotTrueMaxPoint;
    int ii;
    // check each row to find min and max
    for (i = 0; i < m; i++) {
        maxRow = *(*(a+i)+0);
        maxRowIndex = i;
        maxColumnIndex = 0;
        
        minRow = *(*(a+i)+0);
        minRowIndex = i;
        minColumnIndex = 0;
        // determinate max and min elements and indexes in row
        for (j = 1; j < n; j++) {
            // find max element in row
            if (*(*(a+i)+j) > maxRow) {
                maxRow = *(*(a+i)+j);
                maxRowIndex = i;
                maxColumnIndex = j;
            }
            // find min element in row
            if (*(*(a+i)+j) < minRow) {
                minRow = *(*(a+i)+j);
                minRowIndex = i;
                minColumnIndex = j;
            }
        }
        // check column: our points are true?
        isNotTrueMinPoint = 0;
        isNotTrueMaxPoint = 0;
        for (ii = 0; ii < m; ii++) {
            if (!isNotTrueMaxPoint && *(*(a+ii)+maxColumnIndex) < maxRow) {
                isNotTrueMaxPoint = 1;
            }
            if (!isNotTrueMinPoint && *(*(a+ii)+minColumnIndex) > minRow) {
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
    // return memory of the maxtrix to the heap
    free(a);
}
