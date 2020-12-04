#include <stdio.h>
void main() {
    // ask user about size of new array
    int n;
    printf("Введите размерность массива: ");
    scanf("%d", &n);
    int a[n];

    // ask user to enter values of new array
    unsigned i;
    for (i = 0; i < n; i++) {
        printf("Введите элемент a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    // display original array
    printf("Исходный массив: {");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n-1) {
            printf(", ");
        }
    }
    printf("}");
    
    // transform array
    int k;
    for (i = 0; i < (int) n/2; i++) {
        k = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = k;
    }
    
    // display transformed array
    printf("\nПреобразованный массив: {");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n-1) {
            printf(", ");
        }
    }
    printf("}");
}
