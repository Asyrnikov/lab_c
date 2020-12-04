#include <iostream>
#include <stdio.h>

int main(){
	
	int a;
	
	printf("Write down a number of month ");
	scanf("%d", &a);
	
	if(a == 1 || a == 2 || a == 12)
	   printf("Winter");
	else if(a>2 && a<=5)
	   printf("Spring");
	else if(a>5 && a<=8)
	   printf("Summer");
	else if( a == 0)
	   printf("Wrong number");
	else 
	   printf("Autumn");
     
	return 0;
}
