#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jaco.h"
#include "matrix.h"
#include "gseid.h"
#include "update.h"

int main(){
	int N = 13;
	double ** f = dmalloc_2d(N+2,N+2);
	double ** u1 = dmalloc_2d(N+2,N+2);
	double ** u2 = dmalloc_2d(N+2,N+2);
		
	initialize(u1,u2,f,N+2);	

	print(f,N+2);
	print(u1,N+2);

	u1 = jacobi(u1,u2,f,N+2,200,0.0005);
	//u1 = gseidel(u1,f,N+2,1000,0.0005);

	printf("Final result:\n");
	print(u1,N+2);

	return(0);	
}
