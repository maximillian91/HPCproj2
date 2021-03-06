#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gseid.h"
#include "update.h"

double ** gseidel(double **u,double **f,int N,int maxit,double tol){
	int it = 0;
	double frob = tol+1;
	double deltasq = 4.0/((N-1)*(N-1));
	while(it < maxit && frob>tol){
		frob = update(u,u,f,N,deltasq);
		it++;
	}
	if(it < maxit)
		printf("Converged over %d iterations!\n",it);
	else
		printf("Didn't converge!");

	return u;
}
