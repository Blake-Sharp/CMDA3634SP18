#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
