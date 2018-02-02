#include <stdlib.h>
#include <stdio.h>

// gcd code again to be used in determining if a number is coprime or not
// there has to be a better way than writing this over and over
int gcd(int a, int b){

	if (a == 0 || b == 0)
		return 0;

	if (a == b)
		return a;

	if (a > b)
		return gcd(a-b,a);
	return gcd(a, b-a);
}

// main method
void main(){

	//initialization of variables
	int N1, N2;

	printf("Enter the first number:");
	scanf("%d", &N1);

	printf("Enter the second number:");
	scanf("%d", &N2);

	
	if (gcd(N1,N2) == 1)
		printf("%d and %d are coprime.\n", N1, N2);
	else
		printf("%d and %d are not coprime.\n", N1, N2);

}
