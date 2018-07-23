#include<stdio.h>

int BinSearch(int arr[],int r,int key){
	int l=0;
	int mid=(r+l)/2;
	while(r>=l){
		//printf("\nr is %d, l is %d",r,l);
		mid=(r+l)/2;
		if(arr[mid]==key){
			//printf("\na");
			return mid;
		}
		else if(arr[mid]>key){
			r=mid-1;
			//printf("\nb");
		}
		else{
		 	l=mid+1;
		 	//printf("\nc");
		 }
	}
	if(arr[mid]<key){
		//printf("\nmid is %d",mid);
		return (mid+1);
	}
	else return mid;
}

void print(int arr[],int p){
	int i;
	for(i=0;i<=p;++i)
		printf("%d ",arr[i]);
}

void Sort(int arr[],int p){
	if(p==0){
		//printf("\np is 0");
		return;
	}
	else{
		
		Sort(arr,p-1);
		int key=arr[p];
		//printf("\np is %d",p);
		//printf("\nkey is %d",key);
		int i=BinSearch(arr,p-1,key);
		//printf("\ni is %d",i);
		int j=p-1;
		while(j>=i){
			arr[j+1]=arr[j];
			j--;
		}
		arr[i]=key;
		//printf("\nprinting till %d\n",p);
		//print(arr,p);
	}
}

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
	
	Sort(arr,size-1);
	
	printf("\n The sorted array is\n");
	
	for(i=0;i<size;++i)
		printf("%d ",arr[i]);
	printf("\n");	
}

