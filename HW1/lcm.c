#include <stdlib.h>
#include <stdio.h>



//gcd code to be used in lcm
int gcd(int a, int b){
	if(a == 0 || b == 0)
		return 0;

	if(a == b)
		return a;

	if(a > b)
		return gcd(a-b, a);
	return gcd(a, b-a);
}



//lcm code to be used in main
int lcm(int a, int b){
	return (a*b)/gcd(a,b);

}



//main driver method
void main(){

	int N1, N2;

	//writes text on screen and scans for first two numbers
	printf("Enter the first number:");
	scanf("%d", &N1);

	printf("Enter the second number:");
	scanf("%d", &N2);

	printf("The least common multiple of %d and %d is %d\n",N1, N2, lcm(N1,N2));
	


}
