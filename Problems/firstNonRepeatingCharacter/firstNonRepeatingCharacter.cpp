#include <iostream>
#include <unordered_map>

char firstNonRepeatingCharacter(const std::string &str)
{
	std::unordered_map<char, int> seed;

	for (auto i : str)
		seed[i]++;
	for (auto i : str)
		if (seed[i] == 1)
			return i;
	return '\0';
}

int main()
{
	std::cout << firstNonRepeatingCharacter("aa bvvd") << std::endl;
}
