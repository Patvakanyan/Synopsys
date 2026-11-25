#include <vector>
#include <iostream>

void max_heapify(std::vector<int> &arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		max_heapify(arr, n, largest);
	}
}

void build_max_heap(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i)
		max_heapify(arr, n, i);
}

void heapSort(std::vector<int> &arr)
{
	build_max_heap(arr);
	int n = arr.size();
	for (int i = n - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		max_heapify(arr, i, 0);
	}
}

int main()
{
	std::vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int n = arr.size();

	heapSort(arr);
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
}
