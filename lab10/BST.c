#include<stdio.h>
#include<stdlib.h>


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


void main()
{
	struct node *root = NULL;
	int temp, n,i;
	printf("How many elements to be sorted?");
	scanf("%d", &n);
	printf("Enter the numbers: ");
	scanf("%d", &temp);
	root = insert(root,temp);
	for( i=0;i<n-1;i++)
	{
		temp =0;
		scanf("%d", &temp);
		insert(root,temp);
	} 
	
	printf("The sorted array is: ");
	inorder(root);
	printf("\n");
}
