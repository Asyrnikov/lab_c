#include <iostream>
#include <math.h>

// r = a/koren iz 2
int main() {

	int b,r,diag,diam;
	
	
	printf("Vvedite radius kruga ");
	scanf("%d", &r);
	diam = 2*r;
	
	printf("Vvedite storony kvadrata b ");
	scanf("%d", &b);
	diag = ((2*b)/pow(2,1/2));
	
	if (diag<=diam) 
	   printf("It is possible");
	else 
	   printf("It's impossible");
	
	return 0;
}
