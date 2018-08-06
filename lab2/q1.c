#include<stdio.h>
#include<time.h>

void merge(int arr[],int l,int m,int r){
	int arrL[50],arrR[50];
	int i,j,k;
	for(i=0;i<m-l+1;++i)
		arrL[i]=arr[i+l];
		
	for(i=0;i<r-m;++i)
		arrR[i]=arr[i+m+1];
	i=0,j=0,k=l;
	
	while(i<m-l+1 && j< r-m){
		if(arrL[i]<arrR[j]){
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

void mergeSort(int arr[],int l,int r){
	if(l!=r){
		int m=(l+r)/2;
		printf("\nm=%d, l=%d, r=%d",m,l,r);
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
		
	}
}

main(){
	int arr[100],n,i;
	clock_t t;
	printf("\nenter the size of array ");
	scanf("%d",&n);
	printf("\nenter %d numbers ",n);
	
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	printf("\nsorting the array");
	t=clock();
	mergeSort(arr,0,n-1);
	t=clock()-t;
	double d=((double)t)/CLOCKS_PER_SEC;
	printf("\nprinting the array\n ");
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\ntime taken is %f\n",d);	
}

