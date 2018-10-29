// C program for Red-Black Tree insertion
#include<stdio.h>
#include<stdlib.h>
 
//A Red-Black tree node structure
struct node
{
    int data;     // for data part
    int colour;  // for colour property 0 for black 1 for red
 
    //links for left, right children and parent
    struct node *left, *right, *parent;
};
 
typedef struct node node; 
// Left Rotation
void leftRotate(node **root,node *x)
{
    //y stored pointer of right child of x
    node *y = x->right;
 
    //store y's left subtree's pointer as x's right child
    x->right = y->left;
 
    //update parent pointer of x's right
    if (y->left != NULL)
        y->left->parent = x;
 
    //update y's parent pointer
    y->parent = x->parent;
 
    //if x's parent is not null 
    if (x->parent != NULL){
        // store y at the place of x
        if (x == x->parent->left)
            x->parent->left = y;
        else x->parent->right = y;
    }
    else *root=x;
    // make x as left child of y
    y->left = x;
 
    //update parent pointer of x
    x->parent = y;
}
 
 
// Right Rotation (Similar to LeftRotate)
void rightRotate(node **root,node *y)
{
    node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent != NULL){
        if (y == y->parent->left)
            y->parent->left = x;
        else y->parent->right = x;
    }
    else *root=x;
    x->right = y;
    y->parent = x;
}

// Utility function to insert newly node in RedBlack tree
void Tinsert(node **root, node* z)
{
    node *x=*root,*y=NULL;
    while(x!=NULL){
        y=x;
        if(z->data<x->data) x=x->left;
        else x=x->right;
    }
    z->parent=y;
    if(y==NULL) *root=z;
    else if(z->data<y->data) y->left=z;
    else y->right=z;
}
 
// Utility function to fixup the Red-Black tree after standard BST insertion
void RBinsert(node **root,int data)
{
    node *x = (node*)malloc(sizeof(node));
    x->data = data;
    x->left = x->right = x->parent = NULL;
    Tinsert(root,x);
    
    x->colour=1;
    // iterate until z is not the root and z's parent colour is red
    while (x!=*root && x->parent->colour == 1)
    {
        node* y;
        // Find uncle and store uncle in y
        if (x->parent == x->parent->parent->left){
            y = x->parent->parent->right;
 
            if (y->colour == 1){
                y->colour = 0;
                x->parent->colour = 0;
                x->parent->parent->colour = 1;
                x = x->parent->parent;
            }
     
            else{
                if(x=x->parent->right){
                    x=x->parent;
                    leftRotate(root,x);
                }
                x->parent->colour=0;
                x->parent->parent->colour=1;
                rightRotate(root,x->parent->parent);
            }
        }
        
        else{
            y = x->parent->parent->left;
 
            if (y->colour == 1){
                y->colour = 0;
                x->parent->colour = 0;
                x->parent->parent->colour = 1;
                x = x->parent->parent;
            }
     
            else{
                if(x=x->parent->left){
                    x=x->parent;
                    rightRotate(root,x);
                }
                x->parent->colour=0;
                x->parent->parent->colour=1;
                leftRotate(root,x->parent->parent);
            }
        }
        
        
    }
    (*root)->colour = 0; //keep root always black
}
 

// A utility function to traverse Red-Black tree in inorder fashion
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
 
/* Drier program to test above function*/
int main()
{
    //making some random root
    node *root=NULL;
    RBinsert(&root,10);
    RBinsert(&root,20);
    //RBinsert(&root,30);
    printf("inorder Traversal Is : ");
    inorder(root);
 
    return 0;
}
