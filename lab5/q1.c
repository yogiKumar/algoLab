#include <stdio.h>

int partition(int arr[],int l,int r){
    
    int key=arr[l];
    int i,j;
    for(i=l,j=l+1;j<=r;++j){
        if(arr[j]<key){
            int temp=arr[j];
            i=i+1;
            arr[j]=arr[i];
            arr[i]=temp;
           }
    }
    
    arr[l]=arr[i];
    arr[i]=key;
    return i;
  
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int k=partition(arr,l,r);
        //printf("\nl is %d,r is %d,k is %d\n",l,r,k);
        quicksort(arr,l,k-1);
        quicksort(arr,k+1,r);
    }   
}

main(){
	int arr[100],n,i;

	printf("\nenter the size of array ");
	scanf("%d",&n);
	printf("\nenter %d numbers ",n);
	
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	printf("\nsorting the array");
	
	quicksort(arr,0,n-1);
	
	printf("\nprinting the array\n ");
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	
}

        
