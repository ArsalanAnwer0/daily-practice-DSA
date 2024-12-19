// Hi Today I will again be doing all the concepts of DSA I know so far
// Linked List
//  Singly/Doubly/Circular
// Stacks
// Queue
// Tree
// BST
// Heap
// Graph
// HashMap
// Linear/Binary Search
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <queue>
using namespace std;
// singly linked list
class node
{
public:
	int data;
	node *next;
	// constructor
	node(int value) : data(value), next(nullptr) {}
	// destructor
	~node()
	{
		int value = this->data;
		if (this->next != nullptr)
		{
			delete this->next;
			this->next = nullptr;
		}
		cout << "Memory free of " << value << endl;
	}
};
void insertAtHead(node *&head, node *&tail, int d)
{
	if (head == nullptr)
	{
		node *newNode = new node(d);
		head = tail = newNode;
		return;
	}
	node *newNode = new node(d);
	newNode->next = head;
	head = newNode;
}
void printLL(node *head, node *tail)
{
	node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl
		 << "Head: " << head->data << endl
		 << "Tail: " << tail->data << endl;
}
void insertAtTail(node *&head, node *&tail, int d)
{
	if (tail == nullptr)
	{
		node *newNode = new node(d);
		head = tail = newNode;
		return;
	}
	node *newNode = new node(d);
	tail->next = newNode;
	tail = newNode;
}
void insertAtAnyPosition(node *&head, node *&tail, int pos, int d)
{
	if (pos == 1)
	{
		insertAtHead(head, tail, d);
		return;
	}
	int count = 1;
	node *temp = head;
	while (count < pos - 1)
	{
		count++;
		temp = temp->next;
	}
	node *newNode = new node(d);
	// what if we are inserting at last node
	if (temp->next == nullptr)
	{
		tail = newNode;
	}
	// inserting at middle node
	newNode->next = temp->next;
	temp->next = newNode;
}
void deleteNode(node *&head, node *&tail, int pos)
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "Linked list is empty! Nothing to delete!";
		return;
	}
	node *curr = head;
	node *prev = nullptr;
	int count = 1;
	while (count < pos)
	{
		prev = curr;
		curr = curr->next;
		count++;
	}
	if (curr->next == nullptr)
	{
		tail = prev;
	}
	prev->next = curr->next;
	curr->next = nullptr;
	delete curr;
}
class tree
{
public:
	int data;
	tree *left, *right;

	// constructor
	tree(int value) : data(value), left(nullptr), right(nullptr)
	{
	}
};
tree *iteratively()
{
	int rootValue, leftChild, rightChild;
	queue<tree *> q;
	cout << "Enter root value: ";
	cin >> rootValue;
	if (rootValue == -1)
	{
		return nullptr;
	}
	tree *root = new tree(rootValue);
	q.push(root);

	while (!q.empty())
	{
		tree *temp = q.front();
		q.pop();
		cout << "Enter left child of " << temp->data << ": ";
		cin >> leftChild;
		if (leftChild != -1)
		{
			temp->left = new tree(leftChild);
			q.push(temp->left);
		}
		cout << "Enter right child of " << temp->data << ": ";
		cin >> rightChild;
		if (rightChild != -1)
		{
			temp->right = new tree(rightChild);
			q.push(temp->right);
		}
	}
	return root;
}
// recursively
tree *recursively()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return nullptr;
	}
	tree *root = new tree(d);
	cout << "Enter left child of " << root->data << ": ";
	root->left = recursively();
	cout << "Enter right child of " << root->data << ": ";
	root->right = recursively();
	return root;
}
// traversal in tree
void inOrder(tree *root)
{
	if (root == nullptr)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
// Binary Search Tree

// creating a BST
tree *BST(tree *root, int value)
{
	if (root == nullptr)
	{
		return new tree(value);
	}

	if (root->data > value)
	{
		root->left = BST(root->left, value);
	}

	if (root->data < value)
	{
		root->right = BST(root->right, value);
	}

	return root;
}

tree *helperFunction()
{
	tree *root = nullptr;
	int rootValue, value;
	cout << "Enter root value: ";
	cin >> rootValue;
	if (rootValue != -1)
	{
		root = BST(root, rootValue);
		while (true)
		{
			cout << "Enter child value: ";
			cin >> value;
			if (value != -1)
			{
				root = BST(root, value);
			}
			else
			{
				break;
			}
		}
	}
	return root;
}
// how to search in BST
bool searchBST(tree *root, int value)
{
	// if not found
	if (root == nullptr)
	{
		return false;
	}
	// if value found
	if (root->data == value)
	{
		return true;
	}
	// search left sub tree
	if (root->data > value)
	{
		return searchBST(root->left, value);
	}
	// search right sub tree
	if (root->data < value)
	{
		return searchBST(root->right, value);
	}
	return false;
}
tree *minValue(tree *root)
{
	tree *temp = root;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}

// how to delete something in a BST
tree *deleteNode(tree *&root, int value)
{
	// base case
	if (root == nullptr)
	{
		// value not found
		return nullptr;
	}
	// base case
	if (root->data == value)
	{
		// value found

		// 0 child
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		// 1 child
		if (root->left != nullptr && root->right == nullptr)
		{
			// left child exist
			tree *temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == nullptr && root->right != nullptr)
		{
			// right child exist
			tree *temp = root->right;
			delete root;
			return temp;
		}
		// two child case
		if (root->right != nullptr && root->left != nullptr)
		{
			int val = minValue(root->right)->data;
			root->data = val;
			root->right = deleteNode(root->right, val);
			return root;
		}
	}
	// searching for value
	// seraching left sub tree
	if (root->data > value)
	{
		root->left = deleteNode(root->left, value);
	}
	// searching right sub tree
	if (root->data < value)
	{
		root->right = deleteNode(root->right, value);
	}
	return root;
}
int main()
{
	tree *root = nullptr;
	root = helperFunction();
	inOrder(root);
	root = deleteNode(root, 15);
	cout << endl;
	inOrder(root);
	return 0;
}
