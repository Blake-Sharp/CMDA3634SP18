#include <stdlib.h>
#include <stdio.h>


//This issue with computational load seems to be fine, yet when using integers larger
//than the available integer range of C (-2,147,483,648 to 2,147,483,647) the function fails
//to work properly. The int seems to have wraparound logic, so if I choose a number too large,
//it moves to the negative side by the amount over this max number.

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
