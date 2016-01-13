#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jaco.h"
#include "update.h"

double ** jacobi(double **u1, double **u2, double **f, int N, int maxit,double tol){
	int it = 0;
	double frob;
	double deltasq = 4.0/(N*N);
	while(it < maxit){
		frob = update(u1,u2,f,N,deltasq);
		//printf("Iteration %d\n",it+1);
		//printf("Frob = %f\n",frob);
		//print(u1,N);
		it++;

		if(frob <= tol){
			printf("Converged! Over %d iterations!\n",it);
			return u1;
		}
		if(it == maxit){
			printf("Didn't converge!");
			return u1;
		}
		
		frob = update(u2,u1,f,N,deltasq);
		//printf("Iteration %d\n",it+1);
		//printf("Frob = %f\n",frob);
		//print(u2,N);
		it++;
		if(frob <= tol){
			printf("Converged! Over %d iterations!\n",it);
			return u2;
		}
	}
	printf("Didn't converge!");
	return u2;
}
