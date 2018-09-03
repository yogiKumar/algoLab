#include <stdio.h>
#include <stdlib.h>

void cntSort(int arr[],int n,int exp){
    int aux[10],i,ans[n];
    
    for(i=0;i<10;++i)
        aux[i]=0;
        
    for(i=0;i<n;++i)
        aux[(arr[i]/exp)%10]++;
        
    for(i=1;i<10;++i)
        aux[i]+=aux[i-1];
        
    for(i=n-1;i>=0;--i){
        ans[aux[(arr[i]/exp)%10]-1]=arr[i];
        aux[(arr[i]/exp)%10]--;
    }   
    
    for(i=0;i<n;++i)
        arr[i]=ans[i];
}

main(){

    int n,i,exp;
    
    printf("\nenter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nenter %d elements one by one: \n",n);
    
    int m=-1;
    for(i=0;i<n;++i){
        scanf("%d",&arr[i]);
        if(m<arr[i]) m=arr[i];
    }
    printf("\nmaximum element is %d\n",m);
    
    printf("\ndoing radix sort..........\n");
    
    for(exp=1;m/exp>0;exp*=10)    
        cntSort(arr,n,exp);
    
    
    for(i=0;i<n;++i)
        printf("%d ",arr[i]);
    
    printf("\n");
}
