#include<stdio.h>

main(){
	int arr[10];
	printf("\nEnter the size ");
	int size;
	scanf("%d",&size);
	printf("\nThe size is %d, enter %d numbers one by one\n",size,size);
	int i;
	for(i=0;i<size;++i)
		scanf("%d",&arr[i]);
	
	printf("\n.....................sorting.....................");
	
	for(i=1;i<size;++i){
		int key=arr[i];
		int j=i-1;
		while(arr[j]>key && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	
	printf("\n The sorted array is\n");
	
	for(i=0;i<size;++i)
		printf("%d ",arr[i]);
	printf("\n");	
}

