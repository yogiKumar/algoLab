#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// A linked list node 
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

typedef struct Node node; 
main(){
	srand(time(NULL));
	int r,w;
	printf("\nenter the value of r ");
	scanf("%d",&r);
	int m=(int)pow(2,r);
	printf("\nsize of array is %d",m);
	
	printf("\nenter the value of w ");
	scanf("%d",&w);
	
	//A is 1519
	int A=1519;
	node arr[m];
	
	int present[m];
	
	printf("\nhow many keys do you want to hash ");
	int l,i;
	scanf("%d",&l);
	
	for(i=0;i<m;++i) present[i]=0;
	int karr[l];
	
	for(i=0;i<l;++i)
		karr[i]=(rand()%100)+100;
		
	for(i=0;i<l;++i){
		
		int h=((karr[i]*A)%(int)pow(2,w)>>(w-r));
		
		node *n=(node*)malloc(sizeof(node));
		
		n->data=karr[i];
		n->next=NULL;
		//hashing
		if(present[h]==0){
			
			arr[h].data=n->data;
			arr[h].next=NULL;
			present[h]=1;
			
		}
		else{
			node * temp=&arr[h];
			while(temp->next)
				temp=temp->next;
			temp->next=n;
		}
	}
	
	
	//printing the hash table
	node *t;
	for(i=0;i<l;++i){
		printf("\n%d --> ",i);
		
		if(present[i]==1){
			t=&arr[i];
			while(t!=NULL){
				printf(" %d, ",t->data);
				t=t->next;
			}
		}
	} 
	printf("\n");
} 
			
