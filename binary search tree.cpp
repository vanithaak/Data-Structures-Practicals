#include<iostream>
using namespace std;
template<class T>
class BSTnode
{
public:
	T info;
	BSTnode<T> *left, *right;
	BSTnode()
	{
		left = right = NULL;
	}
	BSTnode(const T& e, BSTnode<T> *l = 0, BSTnode *r = 0)
	{
		info = e;
		left = l;
		right = r;
	}
};
template<class T>
class BST
{
public:
	BSTnode<T> *root;
//T* Bsearch(BSTnode<T>* p, const T& el);
//void breadthFirst();
	void inorder(BSTnode<T> *p);
	void preorder(BSTnode<T> *p);
	void postorder(BSTnode<T>* p);
	void display(BSTnode<T>*, T);
	void insert(BSTnode<T>*, BSTnode<T>*);
	T maxHeight(BSTnode<T>* );
	void printGivenLevel(BSTnode<T>* , T);
	//void deleteNode(BSTnode<T>*, T);
	BST()
	{
		root = NULL;
	}
};
template<class T>
void BST<T>::display(BSTnode<T> *ptr, T level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (i = 0;i < level;i++)
				cout << "       ";
		}
		cout << ptr->info;
		display(ptr->left, level + 1);
	}
}
template<class T>
void BST<T>::printGivenLevel(BSTnode<T>* root, T level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->info << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}
template <class T>
T BST<T>::maxHeight(BSTnode<T>* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lHeight = maxHeight(node->left);
		int rHeight = maxHeight(node->right);
		if (lHeight > rHeight)
			return(lHeight + 1);
		else return(rHeight + 1);
	}
}
template<class T>
void BST<T>::insert(BSTnode<T> *tree, BSTnode<T> *newnode)
{
	if (root == NULL)
	{
		root = new BSTnode<T>;
		root->info = newnode-> info;
		root->left = NULL;
		root->right = NULL;
		cout << " \n Root node is added";
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newnode);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "\n Node added to left";
			return;
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << " \n Node added to right";
			return;
		}
	}
}
/*template<class T>
T* BST<T>::Bsearch(BSTnode<T>* p, const T& el) const
{
 while (p !=0)
  if(el==p->el)
return &p->el;
else if(el <p->el)
p=p->left;
else
p=p->right;
return 0;
}
template<class T>
void BST<T>::breadthFirst()
{
Queue<BSTnode<T>* queue;
BSTnode<T> *p=root;
if(p !=0)
{
 queue.enqueue(p);
 while(!queue.empty())
 {
  p=queue.dqueue();
visit(p);
if(p->left !=0)
queue.enqueue(p->left);
if(p->right !=0)
queue.enqueue(p->right);
 }
}
}
*/
template<class T>
void BST<T>::inorder(BSTnode<T> *p)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->info << " ";
		inorder(p->right);
	}
}
template<class T>
void BST<T>::preorder(BSTnode<T> *p)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->left);
		preorder(p->right);
	}
}
template<class T>
void BST<T>::postorder(BSTnode<T>* p)
{
	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << " ";
	}
}
int main()
{
	int choice, num, h;
	char ch;
	BST<int> bst;
	BSTnode<int> *temp, *m;
	while (1)
	{
		cout << " \n ------MENU------";
		cout << " \n 1. Insert element";
		cout << " \n 2. Inorder Traversal";
		cout << " \n 3. Preorder Traversal";
		cout << " \n 4. Postorder Traversal";
		cout << " \n 5. Display";
		cout << " \n 6. Height";
		cout << " \n 7. Print given level";
		cout << " \n 8. Exit";
		cout << "\n Enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			temp = new BSTnode<int>;
			cout << " \n Enter the number to be insert";
			cin >> temp->info;
			bst.insert(bst.root, temp);
			break;
		case 2:
			cout << " \n Inorder Traversal of BST ";
			bst.inorder(bst.root);
			cout << endl;
			break;
		case 3:
			cout << " \n Preorder Traversal of BST";
			bst.preorder(bst.root);
			cout << endl;
			break;
		case 4:
			cout << " \n Postorder Traversal of BST";
			bst.postorder(bst.root);
			cout << endl;
			break;
		case 5:
			cout << " \n Display BST";
			bst.display(bst.root, 1);
			cout << endl;
			break;
		case 6:
			h = bst.maxHeight(bst.root);
			cout << "\nHeight=" << h;
			break;
		case 7:
			cout << "Enter level :";
			cin >> h;
			bst.printGivenLevel(bst.root, h );
			break;
		case 8 :
			exit(1);
		default:
			cout << " Wrong choice entered";
		}
	}
}

