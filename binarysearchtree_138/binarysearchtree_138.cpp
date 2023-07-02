#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL;			// Initializing ROOT to null
	}

	void insert(string element)		// Insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL);		// Langkah 1. Allocate memory for the new node
		newNode->info = element;		// Langkah 2. Assign value to the data field of the new node
		newNode->leftchild = NULL;		// Langkah 3.  Make the left child of the new node pint to NULL
		newNode->rightchild = NULL;		// Langkah 3. Make the right child of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode);	// Langkah 4. Locate the node which will be the parent of the node to be inserted

		if (parent == NULL)		// Langkah 5. If the parent is NULL (Tree is empty)
		{
			ROOT = newNode;		// Langkah 5.a. Mark the new node as ROOT
			return;				// Langkah 5.b Exit
		}

		if (element < parent->info)		// Langkah 6. If the value in the data field of the new node is greater than of the parent
		{
			parent->leftchild = newNode;	// Langkah 6.a. Make the left child of the parent point to the new node
		}
		else if (element < parent->info)	// Langkah 7. If the value in the data field of the new node is greater than of the parent
		{
			parent->rightchild = newNode;	// 7.a. Make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// This function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;					// Langkah 1.
		parent = NULL;						// Langkah 
		while ((currentNode != NULL) && (currentNode->info != element))		// Langkah 3.
		{
			parent = currentNode;							// Langkah 3.a
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;		// Langkah 3.b
			else
				currentNode = currentNode->rightchild;		// Langkah 3.c
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}



};
