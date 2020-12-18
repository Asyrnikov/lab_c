// 2. Компоненты файла f – целые двухзначные (отличные от нуля) числа, причем 10
// положительных чисел, 10 отрицательных, и т.д. Получить файл g, в котором записаны сначала 5
// положительных чисел, затем 5 отрицательных и т.д.
#include <stdio.h>
#include <stdlib.h>
int main()
{
  FILE *S1, *S2;
  int x, y, i, n;
  system("cls");
  do {
    printf("Enter the desired amount of numbers in the first file ");
    printf("(min 20 and multiple of 20):\n");
    scanf("%d", &n);
    if (n < 20) {
      printf("Invalid amount of numbers (min 20).\n");
    }
    if (n % 20 != 0) {
      printf("Invalid number (multiple of 20).\n");
    }
  } while (n < 20 || n % 20 != 0);
  printf("Enter %d numbers for the first file ", n);
  printf("(two-digit numbers; first 10 positive numbers, next 10 negative):\n");
  S1 = fopen("S1.txt", "w");

    for (i = 0; i < n; i++) {
      unsigned short isValid;
      do {
        isValid = 1;
        printf("Enter %d number: ", i+1);
        scanf("%d", &x);
        if (i/10%2 == 0) {
          if (x < 10 || x > 99) {
            printf("Enter valid number (between 10 and 99).\n");
            isValid = 0;
          }
        } else {
          if (x > -10 || x < -99) {
            printf("Enter valid number (between -99 and -10).\n");
            isValid = 0;
          }
        }
      } while (!isValid);
      fprintf(S1, "%d\n", x);
    }
  fclose(S1);
  S1 = fopen("S1.txt", "r");
  S2 = fopen("S2.txt", "w");
  while (!feof(S1)) {
    // 1 iteration
    for(i = 0; i < 5; i++) {
        fscanf(S1, "%d\n", &y);
        fprintf(S2, "%d\n", y);
    }
    // 2 iteration
    fseek(S1, 5*4, SEEK_CUR);
    for(i = 0; i < 5; i++) {
      fscanf(S1, "%d\n", &y);
      fprintf(S2, "%d\n", y);
    }
    // 3 iteration
    fseek(S1, ftell(S1)-5*5-5*4, SEEK_SET);
    for(i = 0; i < 5; i++) {
      fscanf(S1, "%d\n", &y);
      fprintf(S2, "%d\n", y);
    }
    // 4 iteration
    fseek(S1, 5*5, SEEK_CUR);
    for(i = 0; i < 5; i++) {
      fscanf(S1, "%d\n", &y);
      fprintf(S2, "%d\n", y);
    }
  }
  fclose(S1);
  fclose(S2);
}
