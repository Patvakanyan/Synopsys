#include "bst.hpp"

BST::BST() : root(nullptr) {}

void BST::insert(int value)
{
	Node *newNode = new Node(value);

	Node *tmp = nullptr;
	Node *current = root;

	while (current)
	{
		tmp = current;

		if (value < current->data)
			current = current->left;
		else if (value > current->data)
			current = current->right;
		else
		{
			delete newNode;
			return;
		}
	}

	if (!tmp)
		root = newNode;
	else if (value < tmp->data)
		tmp->left = newNode;
	else
		tmp->right = newNode;
}

void BST::print(Node *node, int depth) const
{
	if (node == nullptr)
		return;

	print(node->right, depth + 1);
	for (int i = 0; i < depth; ++i)
		std::cout << "    ";
	std::cout << node->data << '\n';
	print(node->left, depth + 1);
}

void BST::print() const
{
	print(root, 0);
}

void BST::clear(Node *del)
{
	if (del == nullptr)
		return;
	clear(del->left);
	clear(del->right);
	delete del;
}
BST::~BST()
{
	clear(root);
	root = nullptr;
}
