#include "vector.hpp"

#include <cassert>
#include <stdexcept>
#include <string>
#include <utility>

namespace
{
	void test_construction_and_access()
	{
		vector2<int> empty;
		assert(empty.get_size() == 0);
		assert(empty.get_capacity() >= empty.get_size());

		vector2<int> values{3, 6, 9};
		assert(values.get_size() == 3);
		assert(values[0] == 3);
		assert(values.at(1) == 6);
		assert(values.get_data()[2] == 9);

		values[0] = 4;
		values.at(1) = 7;
		assert(values[0] == 4);
		assert(values[1] == 7);

		const vector2<int> &constant_values = values;
		assert(constant_values.at(2) == 9);
		bool threw = false;
		try
		{
			(void)values.at(values.get_size());
		}
		catch (const std::out_of_range &)
		{
			threw = true;
		}
		assert(threw);
	}

	void test_capacity_resize_and_push_back()
	{
		vector2<std::string> values;
		values.push_back("first");
		values.push_back(std::string("second"));
		values.grow_and_push("third");
		assert(values.get_size() == 3);
		assert(values[0] == "first");
		assert(values[1] == "second");
		assert(values[2] == "third");

		const std::size_t old_capacity = values.get_capacity();
		values.reserve(old_capacity + 5);
		assert(values.get_capacity() >= old_capacity + 5);
		assert(values.get_size() == 3);
		assert(values[1] == "second");

		values.resize(5);
		assert(values.get_size() == 5);
		assert(values[3].empty());
		values[3] = "fourth";
		values.resize(2);
		assert(values.get_size() == 2);
		assert(values[1] == "second");
	}

	void test_copy_and_move()
	{
		vector2<int> original{1, 2, 3};
		vector2<int> copied(original);
		assert(copied == original);
		copied[0] = 10;
		assert(original[0] == 1);

		vector2<int> assigned{8};
		assigned = original;
		assert(assigned == original);
		assigned = assigned;
		assert(assigned == original);

		vector2<int> moved(std::move(copied));
		assert(moved.get_size() == 3);
		assert(moved[0] == 10);
		assert(copied.get_size() == 0);

		vector2<int> move_assigned{99};
		move_assigned = std::move(moved);
		assert(move_assigned.get_size() == 3);
		assert(move_assigned[0] == 10);
		assert(moved.get_size() == 0);
	}

	void test_comparison_and_operators()
	{
		vector2<int> left{1, 2, 2, 4};
		vector2<int> same{1, 2, 2, 4};
		vector2<int> right{2, 5};
		assert(left == same);
		assert(!(left != same));
		assert(left != right);

		vector2<int> combined = left + right;
		assert(combined.get_size() == 6);
		assert(combined[0] == 1 && combined[4] == 2 && combined[5] == 5);
		left += right;
		assert(left == combined);

		vector2<int> difference_source{1, 2, 2, 4};
		vector2<int> difference = difference_source - right;
		assert(difference.get_size() == 2);
		assert(difference[0] == 1 && difference[1] == 4);
		difference_source -= right;
		assert(difference_source == difference);
	}

	void test_clear_and_size_constructor()
	{
		vector2<int> sized(4);
		assert(sized.get_size() == 4);
		for (std::size_t i = 0; i < sized.get_size(); ++i)
			assert(sized[i] == 0);

		sized.clear();
		assert(sized.get_size() == 0);
		sized.push_back(42);
		assert(sized.get_size() == 1);
		assert(sized[0] == 42);
	}
}

int main()
{
	test_construction_and_access();
	test_capacity_resize_and_push_back();
	test_copy_and_move();
	test_comparison_and_operators();
	test_clear_and_size_constructor();
}
