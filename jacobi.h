#ifndef JACOBI_H
#define JACOBI_H

double ** jacobi(double **u1, double **u2, double **f, int N, int maxit,double tol);
double update(double **uN,double **uO,double **f,int N,double deltaSq);

#endif
