#include <iostream>
#include <stdio.h>
int main() {
	
	int a,b,c,count;
	
	printf("Vvedite 3 chisla (a,b,c) \n"); 
	scanf("%d %d %d", &a, &b, &c);
	count = 0;
	
	if(a > 0){	
	    count++;
		}
	
	if(b > 0){
		count++;	
	}
	
	if(c > 0){
		count++;
	}
	
	printf("Chislo polozhitelnih chisel = %d", count);
	
	return 0;
}
