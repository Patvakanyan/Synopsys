#pragma once

#include <iostream>

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
	Node *root;
	void print(Node *node, int depth) const;

public:
	BST();
	void insert(int value);
	void print() const;

	void remove(int value);// ---

	void clear(Node *del);
	~BST();
};
