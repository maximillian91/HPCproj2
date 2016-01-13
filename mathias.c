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

double update(double **uN,double **uO,double **f,int N,double deltasq){
	int i,j;
	double sum = 0;
	double a;
	for(i = 1;i < (N-1);i++){
		for(j = 1;j < (N-1);j++){
				uN[i][j] = 0.25*(uO[i][j-1]+uO[i][j+1]+uO[i-1][j]+uO[i+1][j]+deltasq*f[i][j]);
				a = (uN[i][j] - uO[i][j]);
				sum += a*a;
		}
	}
	return sqrt(sum);
}

double ** jacobi(double **u1, double **u2, double **f, int N, int maxit){
	int it = 0;
	double frob;
	double deltasq = 4.0/(N*N);
	while(it < maxit){
		frob = update(u1,u2,f,N);
		printf("Iteration %d\n",it+1);
		printf("Frob = %f\n",frob);
		print(u1,N);
		it++;

		if(frob <= 0.4){
			printf("Converged! Over %d iterations!\n",it);
			return u1;
		}
		if(it == maxit){
			printf("Didn't converge!");
			return u1;
		}
		
		frob = update(u2,u1,f,N);
		printf("Iteration %d\n",it+1);
		printf("Frob = %f\n",frob);
		print(u2,N);
		it++;
		if(frob <= 0.4){
			printf("Converged! Over %d iterations!\n",it);
			return u2;
		}
	}
	printf("Didn't converge!");
	return u2;
}

// allocate a double-prec m x n matrix
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


int main(){
	int N = 7;
	double ** f = dmalloc_2d(N+2,N+2);
	double ** u1 = dmalloc_2d(N+2,N+2);
	double ** u2 = dmalloc_2d(N+2,N+2);
		
	initialize(u1,u2,f,N+2);	

	print(f,N+2);
	print(u1,N+2);

	u1 = jacobi(u1,u2,f,N+2,200);
	
	printf("Final result:\n");
	print(u1,N+2);

	return(0);	
}
