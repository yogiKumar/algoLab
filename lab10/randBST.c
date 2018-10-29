#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int key;
	struct node *right, *left;
};

struct node* New(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if(node==NULL) 
		return New(key);
	if(key < node->key)
		node->left = insert(node->left, key);
	if(key > node->key)
		node->right = insert(node->right, key);
	
	return node;

}
void inorder(struct node* root)
{
	if(root!= NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
void swap( int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void main()
{
	struct node *root = NULL;
	int n,i;
	printf("How many elements to be sorted?");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the numbers: ");
	for( i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int index = rand()%n;	
	root = insert(root, arr[index]);
	swap(arr,index,n-1);
	while(n!=1)
	{
		n = n-1;
		index = rand()%n;
		insert(root, arr[index]);
		swap(arr,index, n-1);	
	}
	inorder(root);
	printf("\n");
}
