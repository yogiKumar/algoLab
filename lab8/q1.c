#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int arr[],int n){
    int i;
    for(i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
    
int findMedian(int arr[],int n){
    sort(arr,n);
    return arr[n/2];
}

int partition(int arr[],int l,int r, int x){
    
    int i,j;
    for(i=l;i<r;i++)
        if(arr[i]==x) break;
    
    swap(&arr[i],&arr[r]);
    
    i=l;
    for(j=l;j<=r-1;j++){
        if(arr[j]<=x){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}

int kthsmallest(int arr[],int l,int r,int k){
    if(k>0 && k<=r-l+1){
        int n=r-l+1;
        int i, median[(n+4)/5];
        for(i=0;i<n/5;i++)
            median[i]=findMedian(arr+l+i*5,5);
        if(i*5<n){
            median[i]=findMedian(arr+l+i*5,n%5);
            i++;
        }
        int medofmed=(i==1)?median[i-1]:kthsmallest(median,0,i-1,i/2);
        //printf("\nhello\n");
        int pos=partition(arr,l,r,medofmed);
        //printf("\nhello\n");
        
        if(pos-l==k-1) return arr[pos];
        if(pos-l>k-1) return kthsmallest(arr,l,pos-1,k);
        
        return kthsmallest(arr,pos+1,r,k-pos+l-1);
    }
}


main(){
    int arr[100],n,i,k;

	printf("\nenter the size of array ");
	scanf("%d",&n);
	printf("\nenter %d numbers ",n);
	
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	
	printf("\nenter the order of number you want: ");
	scanf("%d",&k);
	
	int ans=kthsmallest(arr,0,n-1,k);
	printf("\nthe kth(%d) smallest element is: %d\n",k,ans);
} 
