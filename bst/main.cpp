#include "bst.hpp"

#include <iostream>

namespace
{
	void test_empty_tree()
	{
		BST tree;
		tree.clear(nullptr);
	}

	void test_insertion_and_destruction()
	{
		BST tree;
		tree.insert(8);
		tree.insert(3);
		tree.insert(10);
		tree.insert(1);
		tree.insert(6);
		tree.insert(14);

		// Inserting an existing value should leave the tree valid.
		tree.insert(3);

		tree.print();
	}
}

int main()
{
	test_empty_tree();
	test_insertion_and_destruction();
	std::cout << "BST tests passed\n";
	return 0;
}
