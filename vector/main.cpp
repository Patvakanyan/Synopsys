#include "vector.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <utility>

int main()
{
	vector2<int> values;
	assert(values.get_size() == 0);
	assert(values.get_capacity() >= values.get_size());

	values.push_back(10);
	values.push_back(20);
	values.push_back(30);
	assert(values.get_size() == 3);
	assert(values.get_capacity() >= 3);
	assert(values[0] == 10);
	assert(values.at(1) == 20);
	assert(values.get_data()[2] == 30);

	values.at(1) = 25;
	assert(values[1] == 25);

	vector2<int> copied(values);
	assert(copied.get_size() == 3);
	assert(copied[1] == 25);
	copied[0] = 99;
	assert(values[0] == 10);

	vector2<int> moved(std::move(copied));
	assert(moved.get_size() == 3);
	assert(moved[0] == 99);
	assert(copied.get_size() == 0);

	values.clear();
	assert(values.get_size() == 0);
	values.push_back(42);
	assert(values.get_size() == 1);
	assert(values.at(0) == 42);

	vector2<std::string> words;
	words.push_back("hello");
	words.push_back(std::string("vector"));
	words.push_back("growth");
	assert(words.get_size() == 3);
	assert(words[0] == "hello");
	assert(words[1] == "vector");
	assert(words[2] == "growth");
	vector2<std::string> copied_words(words);
	copied_words.clear();
	assert(copied_words.get_size() == 0);
	assert(words[1] == "vector");

	vector2<std::string> moved_words;
	moved_words = std::move(words);
	moved_words.resize(5);

	vector2<int> arr1{1, 2, 3, 3, 4, 5, 5, 6, 41};
	vector2<int> arr2{};
	vector2<int> res = arr1 - arr2;
	for (size_t i = 0; i < res.get_size(); i++)
	{
		std::cout << "res = " << res[i] <<std::endl;
	}


	std::cout << "Moved words size: " << moved_words.get_size() << "\n";
	std::cout << "Moved words capacity: " << moved_words.get_capacity() << "\n";
	std::cout << "vector2 tests passed\n";
	return 0;
}
