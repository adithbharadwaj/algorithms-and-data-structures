
// binary tree code. (binary search tree). here i've used a pointer to root. and passed double pointer as argument to function



/* CONCLUSIONS (important observations) !!!!! :

1) the IN ORDER traversal of a binary search tree ALWAYS, i repeat, ALWAYS results in ascending order sorting 
   of the numbers, irrespective of the input order or the shape (structure) of the tree;

2) the PRE ORDER traversal AND POST ORDER of a BST depend on the shape (structure) of the tree and hence depends on the order in which 
   the numbers are given as input;     

3) hence, the structure or shape of the tree is important for PRE ORDER and POST ORDER TRAVERSALS. therefore, the order in which we give
  the input is very important. (not for IN ORDER);

4) the average time complexity for CREATING A BST is O(n^2) (since we iterate one extra time for every insertion. i.e 1 + 2 + ... + n - 1 
   = n(n - 1)/2 ~ O(n^2) complexity) 
   it can be minimized to O(nlogn) by sorting.      

*/

#include<stdio.h>
#include<stdlib.h>

struct tree{
	
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree node;

void recursive_insert(node **root, int val);
node *search(node *root, int val);
void inOrder(node *root);
void preOrder(node *root);
void postOrder(node *root);
node *Delete(node *root, int val);
node *findMax(node *root);
void iterative_insert(node **root, int val);

int main(){

    int flag = 1, n, val;

    node *root = NULL;
    
    printf("1 -- > insert\n2 -- > search\n3 -- > inOrder\n4 -- > preOrder\n5 -- > postOrder\n6 -- > delete\n");

    while(flag){
         
        printf("Enter your choice: \n"); 
        scanf("%d", &n);

        switch(n){

            case 1: printf("Enter the value: \n");
                    scanf("%d", &val);  
                    iterative_insert(&root, val);
                    break; 
                     
            case 2: printf("Enter the value\n");
                    scanf("%d", &val);  
                    if(search(root, val)){
                       printf("Found\n");   
                    }
                    else{
                    	printf("not found\n");
                    }
                    break;

            case 3: printf("\nIn order traversal is: \n");
                    inOrder(root);
                    break;  

            case 4: printf("\npre order traversal is: \n");
                    preOrder(root);
                    break;

            case 5: printf("\npost order traversal is: \n");
                    postOrder(root);
                    break;      

            case 6: printf("Enter the value to be deleted\n");
                    scanf("%d", &val);
                    Delete(root, val);                                      

        }

    }  
    

	return 0;
}


void recursive_insert(node **root, int val){
   
   node *newNode = (node *) malloc(sizeof(node));
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;

   if(*root == NULL){
        
        *(root) = newNode;      
        return;  
   }

   if(val < (*root)->data){
        
       recursive_insert(&(*root)->left, val);
   }
   else{
   	   
   	   recursive_insert(&(*root)->right, val);
   }

}

void iterative_insert(node **root, int val){

   node *q, *p;
   p = q = *root; 

   node *newNode = (node *) malloc(sizeof(node));
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;

   if(*root == NULL){
        
        *(root) = newNode;      
        return;  
   }

   // traversing to the node to the right or left of which we need to insert the new node.

   while(q != NULL){

      p = q;
      if(val < p->data){
      	 q = p->left;
      }
      else{
      	q = p->right;
      }

   }

   if(val < p->data){

      p->left = newNode;
   }
   else{

   	p->right = newNode;
   }
   

}


node *search(node *root, int val){

   if(root == NULL){
   	   return NULL;
   }     

   if(root->data == val){
   	  return root;
   }
   else if(root->data < val){
   	 return search(root->right, val);
   }	
   else if(root->data > val){
     return search(root->left, val);
   }

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

    if(root == NULL){
        return;
    }

    printf("%d\n", root->data);
    preOrder(root->left);
    preOrder(root->right);
    
}

void postOrder(node *root){

    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n", root->data);
    
}

node *Delete(node *root, int data){

if(root == NULL){
  return root; 
}  
  else if(data < root->data && root->left != NULL){ 
    
    root->left = Delete(root->left,data);
  }
  else if (data > root->data && root->right != NULL){
   
   root->right = Delete(root->right,data);
  }
  
  else {
    // Case 1:  No child
    if(root->left == NULL && root->right == NULL) { 
      free(root);
      root = NULL;
    }
    //Case 2: One child 
    else if(root->left == NULL) {
      node *temp = root;
      root = root->right;
      free(temp);
    }
    else if(root->right == NULL) {
      node *temp = root;
      root = root->left;
      free(temp);
    }
    // case 3: 2 children
    else { 
      node *temp = findMax(root->left);
      root->data = temp->data;
      root->left = Delete(root->left, temp->data);
    }
  }
return root;

}

node *findMax(node *root){
  
while(root->left != NULL){ 
   root = root->right;
}

return root;

}



/* CONCLUSIONS (important observations) !!!!! :

1) the IN ORDER traversal of a binary search tree ALWAYS, i repeat, ALWAYS (EVERY FUCKING TIME) results in ascending order sorting 
   of the numbers, irrespective of the input order or the shape (structure) of the tree;

2) the PRE ORDER traversal AND POST ORDER of a BST depends on the shape (structure) of the tree and hence depends on the order in which 
   the numbers are given as input;     

3) hence, the structure or shape of the tree is important for PRE ORDER and POST ORDER TRAVERSALS. therefore, the order in which we give
  the input is very important. (not for IN ORDER);

4) the average time complexity for CREATING A BST is O(n^2) (since we iterate one extra time for every insertion. i.e 1 + 2 + ... + n - 1 
   = n(n - 1)/2 ~ O(n^2) complexity) 
   it can be minimized to O(nlogn) by sorting.      

*/
