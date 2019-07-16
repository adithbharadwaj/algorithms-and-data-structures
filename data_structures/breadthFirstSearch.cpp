// breadth first search of a binary tree in c++

#include<iostream>
#include<queue>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;
};

node* Insert(node *root,char data) {
	if(root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

void LevelOrder(node *root) {

    if(root == NULL){
    	return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

       node *curr = q.front();
       q.pop(); 
       
       cout << curr->data << " ";
       
       if(curr->left != NULL){
       	  q.push(curr->left);
       }
       if(curr->right != NULL){
       	 q.push(curr->right);
       }

    }
  
}

int main() {

	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */


	node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');

    cout << endl;

	//Print Nodes in Level Order. 
	LevelOrder(root);

	cout << endl;
}
