#include <stdio.h>
#include <math.h>

int main()
{
    int row, col, i, j, e;
    unsigned short hasPositiveElement;
    //ask user to specify the size of the matrix and write answer
    printf("Задайте количество строк матрицы: ");
    scanf("%d", &row);
    printf("Задайте количество столбцов матрицы: ");
    scanf("%d", &col);
    //create cycle and ask user to specify each element of the matrix, write answer 
    int a[row][col];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Введите элемент [%d,%d] матрицы: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    //check matrix if row with negative elements exists
    for (i = 0; i < row; i++) {
        hasPositiveElement = 0;
        for (j = 0; j < col; j++) {
            if (a[i][j] >= 0) {
                hasPositiveElement = 1;
                break;
            }
        }
        //remember the first element of the found string
        if (!hasPositiveElement) {
            e = a[i][0];
            break;
        }
    }
    //create a cycle where we add the previously obtained value to each element of the matrix
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            a[i][j] = a[i][j] + e;
            //print updated matrix
            printf ("Преобразованный элемент [%d,%d] матрицы: %d \n", i, j, a[i][j]);
        }
    }
}

