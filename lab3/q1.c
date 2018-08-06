#include<stdio.h>

void matrixMult(int a[][10],int b[][10],int c[][10],int n){
	int i,j,k;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			c[i][j]=0;
			for(k=0;k<n;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

main(){
	int a[10][10],b[10][10],c[10][10];
	printf("\nenter the size of the matrix: \n");
	int n;
	scanf("%d",&n);
	
	printf("\nenter %d values for first matrix by row\n",n*n);
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&a[i][j]);
			
	printf("\nenter %d values for second matrix by row\n",n*n);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			scanf("%d",&b[i][j]);
	
	matrixMult(a,b,c,n);		
	printf("\nmultiplying the matices ......\n");
	
	printf("\nresultant matrix is\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
			
	
