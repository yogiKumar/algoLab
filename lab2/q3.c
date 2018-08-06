#include<stdio.h>

void matMult(int a[][10],int b[][10],int c[][10]){
	int i,j,k;
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			c[i][j]=0;
			for(k=0;k<2;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
}

void powerNum(int fn[][10],int p){
	if(p==1){
		fn[0][0]=1,fn[0][1]=1,fn[1][0]=1,fn[1][1]=0;
	}
	else{
		int a[10][10],c[10][10];
		powerNum(a,p/2);
		if(p%2==0)
			matMult(a,a,fn);
		else{
		 	matMult(a,a,c);
		 	int i,j;
		 	int b[10][10];
		 	b[0][0]=1,b[0][1]=1,b[1][0]=1,b[1][1]=0;
		 	
		 	matMult(b,c,fn);
	 	}
	}
}


main(){
	int fn[10][10],n;
	printf("\nenter the fibonacci term you want ");
	scanf("%d",&n);
	fn[0][0]=1,fn[0][1]=1,fn[1][0]=1,fn[1][1]=0;
	powerNum(fn,n);
	printf("\nfibonacci matrix is \n");
	int i,j;
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("%d ",fn[i][j]);
		}
		printf("\n");
	}
	
	printf("\nanswer is %d\n",fn[0][1]);
}
	
