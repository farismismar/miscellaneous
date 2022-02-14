#include <iostream>
#include <cstddef>

using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node<T>* right = NULL;
	Node<T>* left = NULL;

	Node(T d)
	{
		this->data = d;

		this->right = NULL;
		this->left = NULL;
	}

	~Node()
	{
		cout << "Deleting node with data: " << this->data << endl;
	}
};

template<class T>
void inTraverse(Node<T>* root)
{
	// Inorder (Left, Root, Right)
	if (root->left != NULL)
		inTraverse(root->left);
	cout << root->data << endl;
	if (root->right != NULL)
		inTraverse(root->right);
}

template<class T>
void preTraverse(Node<T>* root)
{
	// Preorder (Root, Left, Right)
	cout << root->data << endl;
	if (root->left != NULL)
		preTraverse(root->left);
	if (root->right != NULL)
		preTraverse(root->right);
}

template<class T>
void postTraverse(Node<T>* root)
{
	// Postorder (Left, Right, Root) 
	if (root->left != NULL)
		postTraverse(root->left);
	if (root->right != NULL)
		postTraverse(root->right);
	cout << root->data << endl;
}


template<class T>
void cleanTree(Node<T>* root)
{
	// Cleaning the tree up is through post-order traversal.
	if (root->left != NULL)
		cleanTree(root->left);
	
	if (root->right != NULL)
		cleanTree(root->right);

	delete root;
}

int main(void)
{
	Node<int>* root = new Node<int>(0);
	root->left = new Node<int>(1);
	root->right = new Node<int>(2);
	root->left->right = new Node<int>(3);
	root->left->left = new Node<int>(4);	

	cout << "In-order Traversal" << endl;
	inTraverse(root);

	cout << "Pre-order Traversal" << endl;
	preTraverse(root);

	cout << "Post-order Traversal" << endl;
	postTraverse(root);

	cleanTree(root);
	
	return 0;
}

