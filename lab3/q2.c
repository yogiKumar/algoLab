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

void matrixMultD(int a[][10],int b[][10],int c[][10],int d,int sr1,int er1,int sc1,int ec1,int sr2,int er2,int sc2,int ec2){

	//for a
	//int sr1=(t1/2)*d;
	//int er1=sr1+d-1+r;
	//int sc1=(t1%2)*d;
	//int ec1=sc1+d-1;
	
	//for b
	//int sr2=(t2/2)*d;
	//int er2=sr2+d-1;
	//int sc2=(t2%2)*d;
	//int ec2=sc2+d-1;
	if(d==1){
		c[sr1][sc2]=c[sr1][sc2]+a[sr1][sc1]*b[sr2][sc2];
		//printf("%d %d %d %d\n",sr1,sc1,sr2,sc2); 
	}
	else{
		matrixMultD(a,b,c,d/2,sr1,sr1+(d/2)-1,sc1,sc1+(d/2)-1,sr2,sr2+(d/2)-1,sc2,sc2+(d/2)-1);
		matrixMultD(a,b,c,d/2,sr1,sr1+(d/2)-1,sc1+(d/2),sc1+d-1,sr2+(d/2),sr2+d-1,sc2,sc2+(d/2)-1);
		//printf("%d %d %d %d %d %d %d %d\n",sr1,sr1+(d/2)-1,sc1+(d/2)-1,sc1+d-1,sr2+(d/2)-1,sr2+d-1,sc2,sc2+(d/2)-1);
		
		matrixMultD(a,b,c,d/2,sr1,sr1+(d/2)-1,sc1,sc1+(d/2)-1,sr2,sr2+(d/2)-1,sc2+(d/2),sc2+d-1);
		matrixMultD(a,b,c,d/2,sr1,sr1+(d/2)-1,sc1+(d/2),sc1+d-1,sr2+(d/2),sr2+d-1,sc2+(d/2),sc2+d-1);
		
		matrixMultD(a,b,c,d/2,sr1+(d/2),sr1+d-1,sc1,sc1+(d/2)-1,sr2,sr2+(d/2)-1,sc2,sc2+(d/2)-1);
		matrixMultD(a,b,c,d/2,sr1+(d/2),sr1+d-1,sc1+(d/2),sc1+d-1,sr2+(d/2),sr2+d-1,sc2,sc2+(d/2)-1);
		
		matrixMultD(a,b,c,d/2,sr1+(d/2),sr1+d-1,sc1,sc1+(d/2)-1,sr2,sr2+(d/2)-1,sc2+(d/2),sc2+d-1);
		matrixMultD(a,b,c,d/2,sr1+(d/2),sr1+d-1,sc1+(d/2),sc1+d-1,sr2+(d/2),sr2+d-1,sc2+(d/2),sc2+d-1);
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
	
	matrixMultD(a,b,c,n,0,n-1,0,n-1,0,n-1,0,n-1);		
	printf("\nmultiplying the matices ......\n");
	
	printf("\nresultant matrix is\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
