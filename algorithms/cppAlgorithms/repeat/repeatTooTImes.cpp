#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> repeatTooTimes(const std::vector<int> &v)
{
	std::vector<int> first;
	std::vector<int> second;
	int result = 0;
	for (int i = 0; i < v.size(); i++)
		result ^= v[i];
	for (int i = 0; i < v.size(); i++)
	{
		if ((result ^ v[i]) < v[i])
		{
			first.push_back(v[i]);
		}
		else
		{
			second.push_back(v[i]);
		}
	}
	int firstResult = 0;
	for (int i = 0; i < first.size(); i++)
		firstResult ^= first[i];
	int secondResult = 0;
	for (int i = 0; i < second.size(); i++)
		secondResult ^= second[i];
	return std::make_pair(firstResult, secondResult);
}
int main()
{
	std::vector<int> v = {1, 1, 2, 3, 4, 4, 5, 5, 6, 6};
	std::pair<int, int> result = repeatTooTimes(v);
	std::cout << "Two times repeated numbers are: " << result.first << " and "<< result.second << std::endl;
	return 0;
}
