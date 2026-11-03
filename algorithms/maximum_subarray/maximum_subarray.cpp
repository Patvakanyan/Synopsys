
#include <vector>
#include <cmath>
#include <iostream>
#include <climits>
struct SubarrayResult
{
	int start_index;
	int end_index;
	int maximum_sum;

	SubarrayResult(int low, int high, int maxSum)
	{
		start_index = low;
		end_index = high;
		maximum_sum = maxSum;
	}
};

SubarrayResult findCrossSubarray(const std::vector<int>& array, size_t low, size_t mid, size_t high)
{
	int maxLeftSum = INT_MIN;
	int sum = 0;
	int leftMaxIndex = 0;
	for (size_t i = mid; ; --i)
	{
		sum += array[i];
		if (sum > maxLeftSum)
		{
			maxLeftSum = sum;
			leftMaxIndex = static_cast<int>(i);
		}
		if (i == low)
			break;
	}
	int maxRightSum = INT_MIN;
	sum = 0;
	int rightMaxIndex = 0;
	for (size_t i = mid + 1; i <= high; ++i)
	{
		sum += array[i];
		if (sum > maxRightSum)
		{
			maxRightSum = sum;
			rightMaxIndex = static_cast<int>(i);
		}
	}
	return SubarrayResult(leftMaxIndex, rightMaxIndex, maxRightSum + maxLeftSum);
}

SubarrayResult findMaximumSubarray(const std::vector<int>& array, size_t low, size_t high)
{
	if (high == low)
		return SubarrayResult(low, high, array[low]);
	else
	{
		size_t mid = low + (high - low) / 2;
		SubarrayResult leftSide = findMaximumSubarray(array, low, mid);
		SubarrayResult right = findMaximumSubarray(array, mid + 1, high);
		SubarrayResult cross = findCrossSubarray(array, low, mid, high);
		if (leftSide.maximum_sum > right.maximum_sum && leftSide.maximum_sum > cross.maximum_sum)
			return leftSide;
		else if (right.maximum_sum > leftSide.maximum_sum && right.maximum_sum > cross.maximum_sum)
			return right;
		else
			return cross;

	}
}


int main()
{

	std::vector<int> array = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	SubarrayResult result = findMaximumSubarray(array, 0, array.size() - 1);
	std::cout << "Maximum subarray found from index " << result.start_index << " to index " << result.end_index << " with sum " << result.maximum_sum << std::endl;
	return 0;
}
