#include <stdio.h>
#include <stdlib.h>

void cntSort(int arr[],int range,int n,int ans[]){
    int aux[range+1],i;
    
    for(i=0;i<range+1;++i)
        aux[i]=0;
        
    for(i=0;i<n;++i)
        aux[arr[i]]++;
        
    for(i=1;i<range+1;++i)
        aux[i]+=aux[i-1];
        
    for(i=n-1;i>=0;--i){
        ans[aux[arr[i]]-1]=arr[i];
        aux[arr[i]]--;
    }
    
}

main(){
    int n,i;
    
    printf("\nenter the size of array: ");
    scanf("%d",&n);
    int arr[n],ans[n];
    
    printf("\nenter %d elements one by one: \n",n);
    int m=-1;
    for(i=0;i<n;++i){
        scanf("%d",&arr[i]);
        if(m<arr[i]) m=arr[i];
    }
        
    cntSort(arr,m,n,ans);
    
    printf("\nsorting..........\n");
    for(i=0;i<n;++i)
        printf("%d ",ans[i]);
        
}
    
