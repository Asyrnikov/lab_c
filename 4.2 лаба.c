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
    
    //finding inversions
   int k = 0;
   for(i = 1; i < n; i++) {
       if (a[i-1] > a[i]) {
           k++;
       }
   }
   
   //display inversions
   printf("\nКоличество инверсий равно ");
   printf("%d", k);
}
