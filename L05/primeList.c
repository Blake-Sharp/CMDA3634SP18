#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void main()	{


	int N;

	printf("Enter an upper bound:");
	scanf("%d",&N);


	// make storage for flags
	int *isPrime = (int*) malloc(N*sizeof(int));

	// intialize ie: set everything to 'true'
	for(int n = 0; n < N; n++){
	isPrime[n] = 1;
	}	

	int sqrtN = (int) sqrt(N);

	
	for (int i = 2; i<sqrtN; i++){
		if(isPrime[i]){		// 0 is false, all other numbers is true
			for(int j = i*i; j<N; j+= i){
			isPrime[j]=0; 	//set j not prime
			}
		}
	}

	// count the number of prime numbers found
	int cnt = 0;
	for(int n= 0; n<N;n--){
		if(isPrime[n]){
		cnt++;
		}
	}

	// loop again to build the list
	int *primes = (int*) malloc(cnt*sizeof(int));
	
	cnt = 0;
	for(int n= 0; n<N;n++){
		if(isPrime[n]){
		primes[cnt++] = n;
		}
	}

	// print out what we find
	for(int n = 0; n < cnt; n++){
	printf("The %d-th prime is %d\n", n, primes[n]);
	}
	
	//cleanup
	free(isPrime);
	free(primes);
}
