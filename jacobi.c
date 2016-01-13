#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jacobi.h"
#include "matrix.h"


double ** jacobi(double **u1, double **u2, double **f, int N, int maxit,double tol){
	int it = 0;
	double frob;
	double deltaSq = 4.0/((N-1)*(N-1));
	while(it < maxit && frob>tol){
		frob = update(u1,u2,f,N,deltaSq);
		frob = update(u2,u1,f,N,deltaSq);
		it +=2;
	}
	printf("%f ",frob);
	printf("%f\n",tol);
	return u2;
}

double update(double **uN,double **uO,double **f,int N,double deltaSq){
	int i,j;
	double sum = 0.0;
	double a;
	for(i = 1;i < (N-1);i++){
		for(j = 1;j < (N-1);j++){
				uN[i][j] = 0.25*(uO[i][j-1]+uO[i][j+1]+uO[i-1][j]+uO[i+1][j]+deltaSq*f[i][j]);
				a = (uN[i][j] - uO[i][j]);
				sum += a*a;
		}
	}
	return sqrt(sum);
}
