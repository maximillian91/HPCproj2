#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "update.h"

double update(double **uN,double **uO,double **f,int N,double deltasq){
	int i,j;
	double sum = 0;
	double a;
	for(i = 1;i < (N-1);i++){
		for(j = 1;j < (N-1);j++){
				a = uO[i][j];
				uN[i][j] = 0.25*(uO[i][j-1]+uO[i][j+1]+uO[i-1][j]+uO[i+1][j]+deltasq*f[i][j]);
				a -= uN[i][j];
				sum += a*a;
		}
	}
	return sqrt(sum);
}

