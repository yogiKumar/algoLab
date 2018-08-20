#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int l,int r){
   
    //pick a random positon
    double d=((rand()/RAND_MAX)*(r-l))+l;
    int s=(int)d;
    
    //replace with first number
    int temp=arr[s];
    arr[s]=arr[l];
    arr[l]=temp;
    
    int key=arr[l];
    int i,j;
    for(i=l,j=l+1;j<=r;++j){
        if(arr[j]<key){
            temp=arr[j];
            i=i+1;
            arr[j]=arr[i];
            arr[i]=temp;
           }
    }
    
    arr[l]=arr[i];
    arr[i]=key;
    return i;
  
}

void Randquicksort(int arr[],int l,int r){
    if(l<r){
        int k=partition(arr,l,r);
        //printf("\nl is %d,r is %d,k is %d\n",l,r,k);
        Randquicksort(arr,l,k-1);
        Randquicksort(arr,k+1,r);
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
	
	Randquicksort(arr,0,n-1);
	
	printf("\nprinting the array\n ");
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	
}

        
