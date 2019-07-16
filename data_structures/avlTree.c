#include<stdio.h>
#include<stdlib.h>

struct tree{
	
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree node;

void inOrder(node *root);
void preOrder(node *root);

int max(int a, int b){

    return (a > b)? a : b;
}

int height(node *root){

   if(root == NULL){
   	 return 0;
   } 

   return 1 + max(height(root->left), height(root->right));

}

int balcnce(node *n){

   if(n == NULL){
   	return 0;
   }

   return height(n->left) - height(n->right);

}

node *leftRotate(node *root){

    node *x = root->right;
    node *y = x->left;

    x->left = root;
    root->right = y;
   
    return x; 

}

node *rightRotate(node *root){

   node *x = root->left;
   node *y = x->right;

   x->right = root;
   root->left = y;

   return x;

}

node *insert(node *root, int val){

   node *newNode = (node *) malloc(sizeof(node));
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;

   if(root == NULL){

        return newNode;  
   }
   if(val < root->data){
   	 root->left = insert(root->left, val);
   }
   else if(val > root->data){
   	 root->right = insert(root->right, val);
   }
   else{
   	return root;
   }


   int b = balcnce(root);

   // left left case

   if(b > 1 && val < root->left->data){
       return rightRotate(root);  
   }

   // right right case
   if(b < -1 && val > root->right->data){
   	  return leftRotate(root);
   }

   // left right case
   if(b > 1 && val > root->left->data){
      root->left = leftRotate(root->left);
      return rightRotate(root); 
   }

   if(b < -1 && val < root->right->data){
   	  root->right = rightRotate(root->right);
   	  return leftRotate(root);
   }

   return root;

}


int main(){

    int flag = 1, n, val;

    node *root = NULL;
    
    printf("1 -- > insert\n2 -- > inOrder\n");

    while(flag){
         
        printf("Enter your choice: \n"); 
        scanf("%d", &n);

        switch(n){

            case 1: printf("Enter the value: \n");
                    scanf("%d", &val);  
                    root = insert(root, val);
                    break; 
 
            case 2: printf("\nIn order traversal is: \n");
                    inOrder(root);
                    break;  

            case 3: printf("Pre order is: \n");
                    preOrder(root);
                    break;         
        }

    }  
    

	return 0;
}

void inOrder(node *root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d\n", root->data);
    inOrder(root->right);
    
}

void preOrder(node *root){

    if(root != NULL){
        
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right); 
       
    }
  
}
