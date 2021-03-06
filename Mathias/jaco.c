#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jaco.h"
#include "update.h"

double ** jacobi(double **uN, double **uO, double **f, int N, int maxit,double tol){
	int it = 0;
	double frob = tol+1;
	double** temp;
	double deltaSq = 4.0/((N-1)*(N-1));
	while(it < maxit && frob>tol){
		frob = update(uN,uO,f,N,deltaSq);
		temp = uN;
		uN = uO;
		uO = temp;
		it++;
	}
	if(it < maxit)
		printf("Converged over %d iterations!\n",it);
	else
		printf("Didn't converge!");

	return uO;
}
