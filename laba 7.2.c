//Ввести строку и удалить из неё лишние пробелы. Полученную строку вывести

#include <stdio.h>

int main()
{
    int i, j;
    char myString[31];
    printf("Введите строку с количеством элементов не более 30: ");
    fgets(myString, 31, stdin); 
    for (i = 0; i < 30; i++) {
        if (myString[i] == ' ' && myString[i+1] == ' ') {
            // delete myString[k]
            for (j = i + 1; j < 31; j++) {
                myString[j] = myString[j+1];
            }
            // recheck the same char again
            i--;
        }
    }
    
    printf("Исправленная строка: %s", myString);
}
