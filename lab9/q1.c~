#include <stdio.h>
#include <stdlib.h>


// A linked list node 
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

typedef struct Node node; 
main(){
	int m,k;
	printf("\nenter the size of array ");
	scanf("%d",&m);
	node arr[m];
	
	int present[m];
	
	printf("\nhow many keys do you want to hash ");
	int l,i;
	for(i=0;i<m;++i) present[i]=0;
	
	scanf("%d",&l);
	for(i=0;i<l;++i){
		printf("\nenter the key ");
		//printf("\nhello");
		scanf("%d",&k);
		
		int h=k%m;
		
		node *n=(node*)malloc(sizeof(node));
		
		n->data=k;
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
		//printf("\nend of %d iteration",i);
	}
	
	//search for a key
	
	
	printf("\nenter the key you want to search for ");
	int key;
	scanf("%d",&key);
	//searching
	int hash=key%m;
	node * t;
	if(present[hash]==0) printf("\nkey not found!");
	else{
		t=&arr[hash];
		while(t!=NULL && t->data!=key)
			t=t->next;
		
		if(t!=NULL) printf("\nkey found!");
		else printf("\nkey not found!");
	}
	
	//printing the hash table
	
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
			
