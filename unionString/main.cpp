#include "unionString.hpp"

#include <string>
#include <iostream>
int main()
{

	unionString str1("Hello");
	unionString str2(" World");
	unionString str3 = str1 + str2;
	std::cout << "str1: " << str1.getData() << std::endl;
	std::cout << "str2: " << str2.getData() << std::endl;
	std::cout << "str3: " << str3.getData() << std::endl;
	std::cout << "Size of union Storage: " << sizeof(Storage) << std::endl;
	std::cout << "Size of unionString: " << sizeof(unionString) << std::endl;
	std::cout << "Size of OptimizedType: " << sizeof(OptimizedType) << std::endl;
	std::cout << "Size of ControlBlock: " << sizeof(ControlBlock) << std::endl;
	std::cout << "Size of std::string: " << sizeof(std::string) << std::endl;
	return 0;
}
