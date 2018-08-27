#include <stdio.h>

void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeapify(int arr[],int i,int n){
    int l=2*i;
    int r=2*i+1;
    
    int max=i;
    if(l<=n && arr[max]<arr[l]) max=l;
    if(r<=n && arr[max]<arr[r]) max=r;
    
    if(max!=i){
        swap(&arr[i],&arr[max]);
        maxHeapify(arr,max,n);
    }
}

void buildHeap(int arr[],int n){
    int i,j;
    for(i=n/2;i>=1;--i){
        maxHeapify(arr,i,n);
        //printf("\nprinting for i = %d\n",i);
        //for(j=1;j<n+1;++j) printf("%d ",arr[j]);
        //printf("\n");
    
    }
        
}

void heapsort(int arr[],int n){
    buildHeap(arr,n);
    swap(&arr[1],&arr[n]);
    int i,j;
    for(i=2;i<n;++i){
        maxHeapify(arr,1,n+1-i);
        swap(&arr[1],&arr[n+1-i]);
        //printf("\nprinting for i = %d\n",i);
        //for(j=1;j<n+1;++j) printf("%d ",arr[j]);
        //printf("\n"); 
    }
}
    
    
main(){
    int n,i;
    int arr[20],res[20];
    printf("\nenter the size of array: ");
    scanf("%d",&n);
    printf("\nenter %d numbers one by one: ",n);
    for(i=1;i<n+1;++i) scanf("%d",&arr[i]);
    
    //buildHeap(arr,n);
    
    //printf("\nbuilding heap");
    //printf("\nheap is :");
    
    //for(i=1;i<n+1;++i) printf("%d ",arr[i]);
    //printf("\n");
    
    printf("\nsorted array is");
    heapsort(arr,n);
    for(i=1;i<n+1;++i) printf("%d ",arr[i]);
    printf("\n");
}
