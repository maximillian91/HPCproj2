#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gseid.h"
#include "update.h"

double ** gseidel(double **u,double **f,int N,int maxit,double tol){
	int it = 0;
	double frob;
	double deltasq = 4.0/(N*N);
	while(it < maxit){
		frob = update(u,u,f,N,deltasq);
		//printf("Iteration %d\n",it+1);
		//printf("Frob = %f\n",frob);
		//print(u,N);
		it++;

		if(frob <= tol){
			printf("Converged! Over %d iterations!\n",it);
			return u;
		}
		if(it == maxit){
			printf("Didn't converge!");
			return u;
		}
	}
}
