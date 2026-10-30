#pragma once

#include <cstddef>

struct ControlBlock
{
	const char *data;
	std::size_t size;
	std::size_t capacity;
	std::size_t refCount;

	ControlBlock();
	void addRefCount();
	void setCapacity(std::size_t cap);
	std::size_t getCapacity() const;
	std::size_t getSize() const;

	void releaseRefCount();
	const char *getData() const;
};
