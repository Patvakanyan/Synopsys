#include "h.hpp"
#include <iostream>

void set_value(int new_value) {
	int &val = get_value();
	val = new_value; // Set the value to new_value
}
