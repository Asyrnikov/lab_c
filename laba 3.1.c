#include <stdio.h>
#include <stdlib.h>
int main()
{
float a,month,year;

for (a = 10000; a<=20000; ++month){
a+=a*0.03/12;
}
year = month/12;
printf("Kolichestvo let = %f", year);

	return 0;
}
