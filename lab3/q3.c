#include<stdio.h>

void matrixAdd(int a[][10],int b[][10],int c[][10],int n){
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			c[i][j]=a[i][j]+b[i][j];
}

void matrixSub(int a[][10],int b[][10],int c[][10],int n){
	int i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			c[i][j]=a[i][j]-b[i][j];
}

void matrixMultS(int x[][10],int y[][10],int z[][10],int n){

	if(n==1){
		z[0][0]=x[0][0]*y[0][0]; 
	}
	else{
		int a[10][10],b[10][10],c[10][10],d[10][10],e[10][10],f[10][10],g[10][10],h[10][10];
		int m[10][10],t[10][10],o[10][10],p[10][10];
		int p1[10][10],p2[10][10],p3[10][10],p4[10][10],p5[10][10],p6[10][10],p7[10][10];

		//to store array subtractions and addtions
		int temp1[10][10];int temp2[10][10];
		int i,j;
		//assign a,b,c,d,e,f,g,h
		//assign a
		for(i=0;i<n/2;++i)
			for(j=0;j<n/2;++j)
				a[i][j]=x[i][j];
		
		//assign b
		for(i=0;i<n/2;++i)
			for(j=n/2;j<n;++j)
				b[i][j-(n/2)]=x[i][j];

		//assign c
		for(i=n/2;i<n;++i)
			for(j=0;j<n/2;++j)
				c[i-(n/2)][j]=x[i][j];

		//assign d
		for(i=n/2;i<n;++i)
			for(j=n/2;j<n;++j)
				d[i-(n/2)][j-(n/2)]=x[i][j];

		//assign e
		for(i=0;i<n/2;++i)
			for(j=0;j<n/2;++j)
				e[i][j]=y[i][j];
		
		//assign f
		for(i=0;i<n/2;++i)
			for(j=n/2;j<n;++j)
				f[i][j-(n/2)]=y[i][j];

		//assign g
		for(i=n/2;i<n;++i)
			for(j=0;j<n/2;++j)
				g[i-(n/2)][j]=y[i][j];

		//assign h
		for(i=n/2;i<n;++i)
			for(j=n/2;j<n;++j)
				h[i-(n/2)][j-(n/2)]=y[i][j];

			
		matrixSub(f,h,temp1,n/2);matrixMultS(a,temp1,p1,n/2);

		matrixAdd(a,b,temp1,n/2);matrixMultS(temp1,h,p2,n/2);

		matrixAdd(c,d,temp1,n/2);matrixMultS(temp1,e,p3,n/2);

		matrixSub(g,e,temp1,n/2);matrixMultS(d,temp1,p4,n/2);

		matrixAdd(a,d,temp1,n/2);matrixAdd(e,h,temp2,n/2);matrixMultS(temp1,temp2,p5,n/2);

		matrixSub(b,d,temp1,n/2);matrixAdd(g,h,temp2,n/2);matrixMultS(temp1,temp2,p6,n/2);

		matrixSub(a,c,temp1,n/2);matrixAdd(e,f,temp2,n/2);matrixMultS(temp1,temp2,p7,n/2);		

		//assign the values to m,t,o,p
		//assign to m
		matrixAdd(p5,p4,m,n/2);matrixSub(m,p2,m,n/2);matrixAdd(m,p6,m,n/2);

		//assign to t
		matrixAdd(p1,p2,t,n/2);

		//assign to o
		matrixAdd(p3,p4,o,n/2);

		//assign to p
		matrixAdd(p1,p5,p,n/2);matrixSub(p,p3,p,n/2);matrixSub(p,p7,p,n/2);

		
		//assign m
		for(i=0;i<n/2;++i)
			for(j=0;j<n/2;++j)
				z[i][j]=m[i][j];
		
		//assign t
		for(i=0;i<n/2;++i)
			for(j=n/2;j<n;++j)
				z[i][j]=t[i][j-(n/2)];

		//assign o
		for(i=n/2;i<n;++i)
			for(j=0;j<n/2;++j)
				z[i][j]=o[i-(n/2)][j];

		//assign p
		for(i=n/2;i<n;++i)
			for(j=n/2;j<n;++j)
				z[i][j]=p[i-(n/2)][j-(n/2)];

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
	
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			c[i][j]=0;
		}
	}
	
	matrixMultS(a,b,c,n);		
	printf("\nmultiplying the matrices ......\n");
	
	printf("\nresultant matrix is\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
