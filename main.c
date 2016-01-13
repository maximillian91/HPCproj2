#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "jacobi.h"

int main(int argc, char* argv[]){
	
	//printf("Final result:\n");
	int N = atoi(argv[1]);
	//printf("%d\n",N);
	double ** f = dmalloc_2d(N+2,N+2);
	double ** u1 = dmalloc_2d(N+2,N+2);
	double ** u2 = dmalloc_2d(N+2,N+2);
	double tol = 0.4;
	int maxIter = 200;

	initialize(u1,u2,f,N+2);	

	//print(f,N+2);
	//print(u1,N+2);
	u1 = jacobi(u1,u2,f,N+2,maxIter,tol);
	
	printf("Final result:\n");
	//print(u1,N+2);

	return(0);	
}

