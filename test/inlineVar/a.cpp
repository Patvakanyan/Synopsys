#include "h.hpp"
#include <iostream>

static int a = 0;
int main() {
	int &val = get_value();
	std::cout << "address: " << &a << std::endl; // Output the address of a
	val = 42; // Set the value to 42
	std::cout << "Value: " << val << std::endl; // Output the value
	set_value(100); // Set the value to 100
	std::cout << "Value: " << val << std::endl; // Output the value
	return 0;
}
