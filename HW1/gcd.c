#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//the recursive gcd function

int gcd(int first, int second){


	//checks for sneaky cases
	if (first == 0 || second == 0)
		return 0;
	
	// base case for the recursive function
	if (first == second)
		return first;

	// homework said to assume a >= b
	if (first > second)
		return gcd(first-second, second);
	return gcd(first, second-first);
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
