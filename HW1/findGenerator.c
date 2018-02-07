#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Here we finally have some computational load issues. The largest prime number I was able to get working was 8191, but the program said there is no generator. I am unsure if there is always a generator for prime numbers in this encryption technique. If so, the program does not run correctly for numbers 8191 and 127. If not, computational load seems to be an issue once we get into the 10,000's. All small prime numbers work fine, but the code is not very elegant, so brute forcing numbers in the 10,000's causes the program to hang. 

void main(){

	int gen;
	int p;

	printf("Enter a prime number:");
	scanf("%d", &p);

	gen = 0; // my "DNE" for generator



for(int j = 2; j < p; j++){
	for (int i = 1; i < p; i++){
 		if((i == p-1) && (((int)(pow(j,i)) %  p) == 1)){ //this is a generator
			gen = j; 
			break;
		}

		if(((int)(pow(j,i)) % p) == 1) // this is not a generator, next number please
			break;
	 }

	if(gen != 0) //implies a generator has been found, can stop looking
		break;
}

	if (gen == 0)
		printf("%d has no generator.\n", p);
	if (gen != 0)
		printf("%d is a generator of Z_%d.\n", gen, p);


}
