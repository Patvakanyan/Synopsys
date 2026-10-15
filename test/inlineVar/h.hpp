#pragma once

inline int &get_value() {
	static int value = 0;
	return value;
}

void set_value(int new_value);
