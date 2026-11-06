#include <iostream>
#include <vector>

int repeatOne(const std::vector<int>& v) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result ^= v[i];
	}
	return result;
}
int main() {
	std::vector<int> v = {1, 1,2,2,3,3,4,4,5,5, 6};
	std::cout << "Only onec time repeated number is: " << repeatOne(v) << std::endl;
	return 0;
}
