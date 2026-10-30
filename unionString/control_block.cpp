#include "control_block.hpp"

ControlBlock::ControlBlock()
	: data(nullptr), size(0), capacity(0), refCount(0)
{
}

void ControlBlock::addRefCount()
{
	++refCount;
}

void ControlBlock::setCapacity(std::size_t cap)
{
	capacity = cap;
}

std::size_t ControlBlock::getCapacity() const
{
	return capacity;
}
std::size_t ControlBlock::getSize() const
{
	return size;
}
void ControlBlock::releaseRefCount()
{
	if (refCount > 0)
	{
		--refCount;
		if (refCount == 0)
		{
			delete[] data;
			data = nullptr;
			size = 0;
			capacity = 0;
			delete this;
		}
	}
}

const char *ControlBlock::getData() const
{
	return data;
}
