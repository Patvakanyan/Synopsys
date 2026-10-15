#include <iostream>
#include <vector>

void printNonRepeatingNumbers(const std::vector<int>& numbers)
{
	int firstXor = 0;
	int index = 0;
	for (int num : numbers) {
		firstXor ^= num;
	}
	while(firstXor) {
		if (firstXor & 1) {
			break;
		}
		index++;
		firstXor >>= 1;
	}

	int firstNonRepeating = 0;
	int secondNonRepeating = 0;
	for (int num : numbers)
	{
		if (num & (1 << index))
			firstNonRepeating ^= num;
		else
			secondNonRepeating ^= num;
	}
	std::cout << "The two non-repeating numbers are: " << firstNonRepeating << " and " << secondNonRepeating << std::endl;
}
int main() {
	std::vector<int> numbers = {1, 2, 3, 4, 5, 4, 3, 2, 1, 7};
	printNonRepeatingNumbers(numbers);
	return 0;
}
