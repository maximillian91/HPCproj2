#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(double ** A,int N){
	int maxit = 10;
	int i,j;
	for(i = 0;i < N;i++){
		for(j = 0;j < N;j++){
			printf("%.2f\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void initialize(double **u1,double **u2,double **f,int N){
	int i,j;
	double tra = (N+2)/2.0;
	int xl = (int)floor(tra);
	int xu = (int)ceil((tra*4.0/3));
	int yl = (int)floor((tra*1.0/3));
	int yu = (int)ceil((2.0/3*tra));
	
	//Initialize f
	for(i = 0;i < N;i++){
		for(j = 0;j < N;j++){
			if(i >= xl && i <= xu && j >= yl && j <= yu)
				f[i][j] = 200;
			else
				f[i][j] = 0;
			if(i == (N-1) || j == 0 || j == (N-1)){
				u1[i][j] = 20;
				u2[i][j] = 20;
			}
			else{
				u1[i][j] = 0;
				u2[i][j] = 0;
			}
		}
	}
}

double ** dmalloc_2d(int m, int n) {
	int i;
	if (m <= 0 || n <= 0) return NULL;
     	double **A = malloc(m * sizeof(double *));
     	if (A == NULL) return NULL;
     	A[0] = malloc(m*n*sizeof(double));
     	if (A[0] == NULL) {
		free(A);
        	return NULL;
     	}
     	for (i = 1; i < m; i++)
         	A[i] = A[0] + i * n;
		return A; 
	}
