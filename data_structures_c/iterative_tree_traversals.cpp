#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
/*
Algorithm: 
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        // Reach the left most Node of the curr Node 
        while (curr !=  NULL)
        {
            // place pointer to a tree node on the stack before traversing the node's left subtree 
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its left subtree.  Now, it's right subtree's turn */
        curr = curr->right;
 
    }
}


/*
Algorithm:

1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack

Right child is pushed before left child to make sure that left subtree is processed first.
*/
void iterativePreorder(struct Node *root)
{
    // Base Case
    if (root == NULL)
       return;
 
    // Create an empty stack and push root to it
    stack<Node *> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct Node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

/*
Algorithm for iterative postOrder traversal:

We use 2 stacks.

1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack

*/
void postOrderIterative(struct Node* root)
{
    if (root == NULL) 
        return;
 
    // Create two stacks
    stack<Node *> s1;
    stack<Node *> s2;
 
    // push root to first stack
    s1.push(root);
    struct Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty())
    {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();

        s2.push(node);
 
        // Push left and right children of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        printf("%d ", node->data);
    }
}
 

int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    cout << endl;
    iterativePreorder(root);
    cout << endl;
    postOrderIterative(root);
    cout << endl;
    return 0;
}