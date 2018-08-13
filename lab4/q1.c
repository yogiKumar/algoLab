#include<stdio.h>

void mergeRow(struct node arr[],int l,int m,int r){
	struct node arrL[50],arrR[50];
	int i,j,k;
	for(i=0;i<m-l+1;++i)
		arrL[i]=arr[i+l];
		
	for(i=0;i<r-m;++i)
		arrR[i]=arr[i+m+1];
	i=0,j=0,k=l;
	
	while(i<m-l+1 && j< r-m){
		if(arrL[i].row<arrR[j].row){
			arr[k]=arrL[i];
			i++;
		}
		else{
			arr[k]=arrR[j];
			j++;
		}
		k++;
	}
	
	while(i<m-l+1){
		arr[k]=arrL[i];
		i++;
		k++;
	}
	
	while(j<r-m){
		arr[k]=arrR[j];
		j++;
		k++;
	}
	
}

void mergeSortRow(int arr[],int l,int r){
	if(l!=r){
		int m=(l+r)/2;
		printf("\nm=%d, l=%d, r=%d",m,l,r);
		mergeSortRow(arr,l,m);
		mergeSortRow(arr,m+1,r);
		mergeRow(arr,l,m,r);
		
	}
}

void mergeCol(struct node arr[],int l,int m,int r){
	struct node arrL[50],arrR[50];
	int i,j,k;
	for(i=0;i<m-l+1;++i)
		arrL[i]=arr[i+l];
		
	for(i=0;i<r-m;++i)
		arrR[i]=arr[i+m+1];
	i=0,j=0,k=l;
	
	while(i<m-l+1 && j< r-m){
		if(arrL[i].col<arrR[j].col){
			arr[k]=arrL[i];
			i++;
		}
		else{
			arr[k]=arrR[j];
			j++;
		}
		k++;
	}
	
	while(i<m-l+1){
		arr[k]=arrL[i];
		i++;
		k++;
	}
	
	while(j<r-m){
		arr[k]=arrR[j];
		j++;
		k++;
	}
	
}

void mergeSortCol(int arr[],int l,int r){
	if(l!=r){
		int m=(l+r)/2;
		printf("\nm=%d, l=%d, r=%d",m,l,r);
		mergeSortCol(arr,l,m);
		mergeSortCol(arr,m+1,r);
		mergeCol(arr,l,m,r);
		
	}
}

struct node{
    int row;
    int col;
    int data;
};

int sparseMult(struct node arr1[],struct node arr2[],struct node arr3[],int s1,int s2){
    int i,j,k;
	for(i=0;i<s1;++i){
		for(j=0;j<s2;++j){
			for(k=0;k<n;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

main(){
    printf("\nenter the dimension of the first matrix: \n");
	int n;
	scanf("%d",&n);
	
	printf("\nenter the no of non zero elements of the first matrix: \n");
	int s1;
	scanf("%d",&s1);
	
	struct node arr1[100];
	printf(" \nenter the row,col,val triplet\n");
	int i;
	int r,c,v;
	for(i=0;i<s1;++i){
	    scanf("%d %d %d",&r,&c,&v);
	    arr1[i].row=r;arr1[i].col=c;arr1[i].data=val;
	}
	
	//sorting the first array
	mergeSortRow(arr1,0,s1-1);
	printf("\nenter the no of non zero elements of the second matrix: \n");
	int s2;
	scanf("%d",&s2);
	
	struct node arr2[100];
	printf(" \nenter the row,col,val triplet\n");
	for(i=0;i<s1;++i){
	    scanf("%d %d %d",&r,&c,&v);
	    arr2[i].row=r;arr2[i].col=c;arr2[i].data=val;
	}
	
	//sorting the second array
	mergeSortCol(arr2,0,s2-1);
	//multiplying the matrices
	int s3;
	struct node arr3[100];
	s3=sparseMult(arr1,arr2,arr3,s1,s2);
	
	
}
	
	
	
	    
