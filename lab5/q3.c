#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){ if(a>b) return b; else return a;}

int max(int a,int b){ if(a>b) return a; else return b;}

void findMinMax(int arr[],int* min1,int* min2,int* max1,int* max2,int l,int r){
    int i;
    for(i=l+1;i<=r;++i){
        *min1=min((*min1),arr[i]);
        *max1=max((*max1),arr[i]);
    }
    
    *min2=*max1;*max2=*min1;
    for(i=l+1;i<=r;++i){
        if(arr[i]!=*min1) *min2=min(*min2,arr[i]);
        if(arr[i]!=*max1) *max2=max(*max2,arr[i]);
    }
}

int partition(int arr[],int l,int r){
   
    //pick a random positon
    double d=(rand()%(r-l))+l;
    int s=(int)d;
    
    
    //find min1,min2,max1,max2
    if(r-l+1>4){
        int min1,min2,max1,max2;
        //int min1=arr[l],min2=arr[r],max1=arr[l],max2=arr[l];
        findMinMax(arr,&min1,&min2,&max1,&max2,l,r);
        if(arr[s]==min1 || arr[s]==min2 || arr[s]==max1 || arr[s]==max2)  return partition(arr,l,r);
    }
    
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

        
