#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "cuda.h"
#include "functions.c"

__device__ int modprodcu(unsigned int a, unsigned int b, unsigned int p){
	unsigned int za = a;
	unsigned int ab = 0;

	while (b>0){
		if(b%2 ==1) ab = (ab+za)%p;
		za = (2*za)%p;
		b /= 2;
	}
	return ab;
}

__device__ int modExpcu(unsigned int a, unsigned int b, unsigned int p){
	unsigned int z = a;
	unsigned int aExpb = 1;

	while(b>0){
		if(b%2==1) aExpb = modprodcu(aExpb,z,p);
		z = modprodcu(z,z,p);
		b /=2;
	}
	return aExpb;
}
	


//Thought I needed this function... turns out I didnt
//__device__ int parallelFind(unsigned int initialP, unsigned int numLoops){
//
  //   	for (unsigned int i=initialP;i<(intialP+numLoops);i++) {
   //   		if (modExp(g,i+1,p)==h) {
        		//printf("Secret key found! x = %u \n", i+1);
     //   		x=i+1;
//			return x;
//		}
//	} 
//
//}


__global__ void findKey(unsigned int g, unsigned int h, unsigned int p, unsigned int *d_x){ 

	int threadid =threadIdx.x;
	int blockid = blockIdx.x;
	int Nblock = blockDim.x;


	int id = threadid + blockid*Nblock;
	
 
	if (id < (p-1)) {
      		if (modExpcu(g,id+1,p)==h) {
        		//printf("Secret key found! x = %u \n", id+1);
        		*d_x =id+1;
		}
	}
}





int main (int argc, char **argv) {

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h, x;
  unsigned int Nints;

  //get the secret key from the user
  printf("Enter the secret key (0 if unknown): "); fflush(stdout);
  char stat = scanf("%u",&x);

  printf("Reading file.\n");

  /* Q3 Complete this function. Read in the public key data from public_key.txt
    and the cyphertexts from messages.txt. */

	FILE *file;
	file = fopen("public_key.txt","r");
	fscanf(file, "%u %u %u %u", &n,&p,&g,&h);
	fclose(file);

FILE *efile;
efile = fopen("message.txt","r");
fscanf(efile,"%u",&Nints);

  unsigned int *Zmessage =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned int *a =
      (unsigned int *) malloc(Nints*sizeof(unsigned int));

for(unsigned int i = 0; i < Nints; i++){
	fscanf(efile,"%u %u",&(Zmessage[i]),&(a[i]));
}
fclose(efile);


unsigned int h_x;

//	h_g = (unsigned int *) malloc(sizeof(unsigned int));
//	h_h = (unsigned int *) malloc(sizeof(unsigned int));
//	h_x = (unsigned int *) malloc(sizeof(unsigned int));
//	h_p = (unsigned int *) malloc(sizeof(unsigned int));

//	h_g = g;
//	h_h = h;
	h_x = 0;
//	h_p = p;

unsigned int *d_x;

//	cudaMalloc(&d_g,sizeof(unsigned int));
//	cudaMalloc(&d_h,sizeof(unsigned int));
	cudaMalloc(&d_x,sizeof(unsigned int));
//	cudaMalloc(&d_p,sizeof(unsigned int));

//	cudeMemcpy(d_g,h_g,sizeof(unsigned int),cudaMemcpyHostToDevice)
//	cudeMemcpy(d_h,h_h,sizeof(unsigned int),cudaMemcpyHostToDevice)
//	cudaMemcpy(d_x,h_x,sizeof(unsigned int),cudaMemcpyHostToDevice);
//	cudeMemcpy(d_p,h_p,sizeof(unsigned int),cudaMemcpyHostToDevice)

  // find the secret key
  if (x==0 || modExp(g,x,p)!=h) {
    printf("Finding the secret key...\n");
	}
    double startTime = clock();
    //for (unsigned int i=0;i<p-1;i++) {
      //if (modExp(g,i+1,p)==h) {
        //printf("Secret key found! x = %u \n", i+1);
        //x=i+1;
	//}
	//}

unsigned int Nthreads = 32;
unsigned int Nblocks = (p-1)/Nthreads;

findKey <<<Nblocks,Nthreads>>>(g,h,p,d_x);
cudeDeviceSynchronize();

cudaMemcpy(&h_x,d_x,sizeof(unsigned int),cudaMemcpyDeviceToHost);

    double endTime = clock();

    double totalTime = (endTime-startTime)/CLOCKS_PER_SEC;
    double work = (double) p;
    double throughput = work/totalTime;

	printf("Secret key found! x = %u \n",h_x);
	printf("It took %d seconds to find the key in cuda.\n", totalTime);
	printf("The work was %d and the throughput was %d.\n",work,throughput);

//cudaFree(d_g);
//cudaFree(d_p);
//cudaFree(d_h);
cudaFree(d_x);

//free(h_g);
//free(g_h);
//free(h_x);
//free(h_p);


  /* Part 2. Start this program by first copying the contents of the main function from 
     your completed decrypt.c main function. */

  /* Q4 Make the search for the secret key parallel on the GPU using CUDA. */

  return 0;
}
