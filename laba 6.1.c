// 2. В одномерном массиве, состоящем из п целых элементов, вычислить:
// - произведение элементов массива с четными номерами;
// - сумму элементов массива, расположенных между первым и последним нулевыми
// элементами.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
 {
    int *ptr, i, n, *a, p = 1, d, sum = 0;
    printf("Введите размерность массива: ");
    scanf("%d", &n);
    int new;
    new = a[n];
    for (i = 0; i < n; i++) {
        printf("Введите %d-й элемент массива: ", i+1);
        scanf("%d", a+i);
    }
    printf("Исходный массив: {");
    for (i = 0; i < n; i++) {
        printf("%d", *(a+i));
        if (i < n-1) {
            printf(", ");
        }
    }
    printf("}\n");
    if(!(ptr=(int*)malloc(n*sizeof(int)))) { 
        puts("Недостаточно памяти"); 
        getch();
        return;
    }
    for (i = 1; i < n; i += 2) {
        if ((i + 1) % 2 == 0) {
            p = p * (*(a+i));
        }
    }
    printf("Произведение элементов массива с четными номерами: %d\n", p);
    d = -1;
    for (i = 0; i < n; i++) {
        if (*(a+i) == 0) {
            d = i;
            break;
        }
    }
    if (d != -1) {
        for (i = n-1; i >= d; i--) {
            if (*(a+i) == 0) {
                // i variable has the number value of the last zero element
                break;
            }
        }
        // find the sum between d and i
        for (d += 1; d < i; d++) {
            sum = sum + *(a+d);
        }
        printf("Сумма элементов массива, расположенных между первым и последним нулевыми элементами: %d", sum);
    } else {
        printf("Нулевых элементов в данном массиве нет");
    }
    free(a);
}
