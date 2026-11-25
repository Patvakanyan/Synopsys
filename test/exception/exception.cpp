#include <exception>
#include <stdexcept>
#include <iostream>
int a()
{
	throw std::exception();
}


int b()
{
	try
	{
		a();
	}
	catch (const std::exception& e)
	{
		throw std::out_of_range("Out of range exception");
	}
	return 0;
}


int main()
{
	try
	{
		b();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Caught an out_of_range exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught a general exception: " << e.what() << std::endl;
	}
	return 0;
}


