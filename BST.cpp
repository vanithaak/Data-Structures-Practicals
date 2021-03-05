#include<iostream>
using namespace std;
template<class t>
class node
{
  public:
         t info;
		 node *next;
		 node(t x, node *n =NULL)
		 {
		    info =x;
			next = n;
		 }
};

template<class t>
class BST
{
    int data;
    BST *left, *right;
	public:
         BST(int value)
         {
          data = value;
          left = right = NULL;
         }
		 int insert(BST*, int);
		 int deletenode(node*, int);
		 BST* minValueNode(node*);
};
int BST::Insert(BST* root, int value)
{
    if (!root) 
    {
        return new BST(value);
    }

    if (value > root->data) 
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

int BST::deleteNode(node* root, int key) 
{ 

    if (root == NULL) return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        node* temp = minValueNode(root->right); 
  
        root->key = temp->key; 
 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

int BST::minValueNode(node* node) 
{ 
     node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}    
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

