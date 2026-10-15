#include "merge.hpp"

#include <iostream>
int main()
{
	std::vector<int> arr = {1, 3, 5, 2, 4};

	mergeSort(arr, 0, arr.size());

	for (auto var : arr)
	{
		std::cout << var << std::endl;
	}
}
