#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Similar int range issues, but I found nothing computationally taxing.


void main(){

	// initialization
	int N, count, upperBound;
	
	//text for screen, and reading input
	printf("Enter a number:");
	scanf("%d", &N);

	count = 0; // used to determine if prime
	upperBound = (int)sqrt(N)+1; // tripped up by the upper bound, but added 1 to be safe


	//determines the amount of divisors
	for (int i = 1; i <= upperBound; i++){
		if(N%i == 0)
			count++;
	}		

	//if only one divisor (1), the number is prime
	if (count > 1)
		printf("%d is not prime.\n", N);
	else
		printf("%d is prime.\n", N);

}
