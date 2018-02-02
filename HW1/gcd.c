#include <stdlib.h>
#include <stdio.h>


//the recursive gcd function

int gcd(int a, int b){


	//checks for sneaky cases
	if (a == 0 || b == 0)
		return 0;
	
	// base case for the recursive function
	if (a == b)
		return a;

	// homework said to assume a >= b
	if (a > b)
		return gcd(a-b, a);
	return gcd(a, b-a);
}



// the main driver that calls gcd
void main(){

	//initializtions
	int N1, N2;

	//screen messages and scanning for numbers
	printf("Enter the first number:");
	scanf("%d",&N1);
	
	printf("Enter the second number:");
	scanf("%d",&N2);
	
	


	printf("The greatest common divisor of %d and %d is %d.\n", N1, N2, gcd(N1,N2));

}
