#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "mpi.h"
#include "functions.h"

int main (int argc, char **argv) {

  MPI_Init(&argc,&argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);

  //seed value for the randomizer 
  double seed = clock()+rank; //this will make your program run differently everytime
  //double seed = rank; //uncomment this and your program will behave the same everytime it's run

  srand(seed);

  //begin with rank 0 getting user's input
  unsigned int n;

  /* Q3.1 Make rank 0 setup the ELGamal system and
    broadcast the public key information */

  //declare storage for an ElGamal cryptosytem
  unsigned int p, g, h, x;

	if(rank==0){	

  printf("Enter a number of bits: "); fflush(stdout);
  char status = scanf("%u",&n);

  //make sure the input makes sense
  if ((n<3)||(n>31)) {//Updated bounds. 2 is no good, 31 is actually ok
    printf("Unsupported bit size.\n");
    return 0;   
  }
  printf("\n");

  //setup an ElGamal cryptosystem
  setupElGamal(n,&p,&g,&h,&x);
}

        int Alice = 0; //Alice in our case  

        unsigned int buf[3];

        if(rank == Alice){
                buf[0] = p;
                buf[1] = g;
                buf[2] = h;
        }

                MPI_Bcast(&buf,
                        3, //int count
                        MPI_UNSIGNED ,
                        Alice,
                        MPI_COMM_WORLD);



        if(rank != Alice){
                p = buf[0];
                g = buf[1];
                h = buf[2];
        }



  //Suppose we don't know the secret key. Use all the ranks to try and find it in parallel
  if (rank==0)
    printf("Using %d processes to find the secret key...\n", size);

  /*Q3.2 We want to loop through values i=0 .. p-2
     determine start and end values so this loop is 
     distributed amongst the MPI ranks  */
  unsigned int N = p-1; //total loop size
  unsigned int start, end;
  
  //start = 0; 
  //end = start + N;

if((N%size)==0){
	start = (N/size)*rank;
	end = start + (N/size);
}

else if(rank < (size-1)){
	int step = (N/size) + 1;
	start = step*rank;
	end = start + step;
}
else if(rank == (size -1)){
	int step = (N/size)+1;
	start = step*rank;
	end = N;
}

double startTime,endTime;

startTime = MPI_Wtime();
 
  //loop through the values from 'start' to 'end'
  for (unsigned int i=start;i<end;i++) {
    if (modExp(g,i,p)==h)
      printf("Secret key found! x = %u \n", i);
  
}
	endTime = MPI_Wtime();

	printf("Time taken for rank %d was %f.\n",rank,(endTime-startTime)); 

  MPI_Finalize();

  return 0;
}
