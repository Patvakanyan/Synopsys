#include "list.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <utility>

namespace
{
	void test_empty_and_push_back()
	{
		DoublyLinkedList<int> values;
		values.pop_back();
		values.pop_front();
		values.push_back(10);
		values.push_back(20);
		values.push_back(30);

		assert(values[0] == 10);
		assert(values[1] == 20);
		assert(values[2] == 30);
	}

	void test_front_and_back_operations()
	{
		DoublyLinkedList<int> values;
		values.push_front(2);
		values.push_front(1);
		values.push_back(3);
		values.push_back(4);

		assert(values[0] == 1);
		assert(values[1] == 2);
		assert(values[2] == 3);
		assert(values[3] == 4);

		values.pop_front();
		values.pop_back();
		assert(values[0] == 2);
		assert(values[1] == 3);

		values.pop_front();
		values.pop_back();
		values.pop_front();
		values.pop_back();
		values.push_back(5);
		assert(values[0] == 5);
	}

	void test_insert_and_remove()
	{
		DoublyLinkedList<int> values{1, 3};
		values.insert(2, 1);
		values.insert(0, 0);

		assert(values[0] == 0);
		assert(values[1] == 1);
		assert(values[2] == 2);
		assert(values[3] == 3);

		values.remove(0);
		values.remove(1);
		assert(values[0] == 1);
		assert(values[1] == 3);

		values.remove(1);
		assert(values[0] == 1);
	}

	void test_constructors()
	{
		DoublyLinkedList<int> initialized{1, 2, 3};
		assert(initialized[0] == 1);
		assert(initialized[1] == 2);
		assert(initialized[2] == 3);

		DoublyLinkedList<std::string> repeated(2, "test");
		assert(repeated[0] == "test");
		assert(repeated[1] == "test");
	}

	void test_copy_and_move()
	{
		DoublyLinkedList<int> original{4, 5, 6};
		DoublyLinkedList<int> copied(original);
		copied[0] = 40;
		assert(original[0] == 4);
		assert(copied[0] == 40);

		DoublyLinkedList<int> moved(std::move(copied));
		assert(moved[0] == 40);

		DoublyLinkedList<int> assigned{1};
		assigned = original;
		assert(assigned[0] == 4);
		assert(assigned[1] == 5);
		assert(assigned[2] == 6);

		DoublyLinkedList<int> move_assigned{99};
		move_assigned = std::move(assigned);
		assert(move_assigned[0] == 4);
		assert(move_assigned[2] == 6);

		original = original;
		assert(original[0] == 4);
	}

	void test_clear()
	{
		DoublyLinkedList<int> values{1, 2, 3};
		values.clear();
		values.push_back(42);
		assert(values[0] == 42);
		values.clear();
		values.clear();
		values.push_back(7);
		values.pop_back();
		values.push_back(8);
		assert(values[0] == 8);
	}
}

int main()
{
	test_empty_and_push_back();
	test_front_and_back_operations();
	test_insert_and_remove();
	test_constructors();
	test_copy_and_move();
	test_clear();

	std::cout << "DoublyLinkedList tests passed\n";
	return 0;
}
