#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left, * right;
};

Node* new_node(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder_traversal(Node* root, unsigned short &counter)
{
	if (root != NULL)
	{
		inorder_traversal(root->left, counter);
		if (root->left != NULL && root->right == NULL)
			counter++;
		cout << root->data << ' ';
		inorder_traversal(root->right, counter);
	}
}

Node* insert_node(Node* node, int data)
{
	if (node == NULL)
		return new_node(data);

	if (data < node->data)
		node->left = insert_node(node->left, data);
	else
		node->right = insert_node(node->right, data);

	return node;
}

Node* delete_node(Node* root, int num_to_delete)
{
	if (root == NULL)
		return root;

	if (root->data > num_to_delete)
	{
		root->left = delete_node(root->left, num_to_delete);
		return root;
	}
	else
		if (root->data < num_to_delete)
		{
			root->right = delete_node(root->right, num_to_delete);
			return root;
		}

	if (root->left == NULL)
	{
		Node* temp = root->right;
		delete root;
		return temp;
	}
	else
		if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
	else
	{
		Node* two_child_parent = root->right;
		Node* replacement = root->right;
		while (replacement->left != NULL)
		{
			two_child_parent = replacement;
			replacement = replacement->left;
		}

		two_child_parent->left = replacement->right;

		root->data = replacement->data;

		delete replacement;
		return root;
	}
}

void binary_tree(void)
{
	cout << "This program is working with binary tree and count nodes with only left child\n\n";

	Node* root = NULL;
	int* array = new int[15];
	int rnd = 0;
	for (int i = 0; i < 15; i++)
	{
		rnd = rand() % 50;
		root = insert_node(root, rnd);
		array[i] = rnd;
	}

	unsigned short only_left_subtree = 0;
	cout << "\nInorder traversal of the tree:\n";
	inorder_traversal(root, only_left_subtree);
	cout << "\nNumber of the nodes with only left child: " << only_left_subtree << '\n';

	cout << "\nDelete node " << array[14];
	root = delete_node(root, array[14]);

	only_left_subtree = 0;
	cout << "\nInorder traversal of the new tree:\n";
	inorder_traversal(root, only_left_subtree);
	cout << "\nNumber of the nodes with only left child: " << only_left_subtree << '\n';

	for (int i = 13; i >= 0; i--)
		root = delete_node(root, array[i]);
	cout << "\nAfter deleting, the tree traversal:\n";
	inorder_traversal(root, only_left_subtree);
	cout << "Clear!\n\n";
	delete[] array;
}

void main()
{
	binary_tree();
	system("pause");
}