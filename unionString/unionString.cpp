#include "unionString.hpp"

#include <new>
#include <string>
#include <utility>

Storage::Storage()
	: ssoMode{}
{
}

Storage::~Storage()
{
}

void unionString::addCOWRefCount()
{
	storage_.controlCOW->addRefCount();
}

void unionString::detach()
{
	const std::size_t size = storage_.controlCOW->size;
	vector2<char> data(storage_.controlCOW->getData(), size);
	storage_.controlCOW->releaseRefCount();
	optimizedType_ = OptimizedType::NonOptimized;
	new (&storage_.heapMode) vector2<char>(std::move(data));
}

unionString::unionString()
	: optimizedType_(OptimizedType::SSO), storage_{}
{
	storage_.ssoMode.ssoSize = 0;
	storage_.ssoMode.ssoData[0] = '\0';
}

void unionString::switchToCOWMode(const char *str, std::size_t size, std::size_t capacity)
{
	optimizedType_ = OptimizedType::COW;
	storage_.controlCOW = new ControlBlock();
	capacity = (capacity == 0) ? size + 1 : capacity;
	char *data = new char[capacity];
	std::memcpy(data, str, size);
	data[size] = '\0';
	storage_.controlCOW->data = data;
	storage_.controlCOW->size = size;
	storage_.controlCOW->setCapacity(capacity);
	storage_.controlCOW->addRefCount();
}

void unionString::switchToSSOMode(const char *str, std::size_t size)
{
	optimizedType_ = OptimizedType::SSO;
	for (size_t i = 0; i < size; i++)
		storage_.ssoMode.ssoData[i] = str[i];
	storage_.ssoMode.ssoData[size] = '\0';
	storage_.ssoMode.ssoSize = size;
}

unionString::unionString(const char *str)
	: optimizedType_(OptimizedType::COW), storage_{}
{
	if (str == nullptr)
	{
		optimizedType_ = OptimizedType::SSO;
		storage_.ssoMode.ssoSize = 0;
		storage_.ssoMode.ssoData[0] = '\0';
		return;
	}
	if (std::strlen(str) > 15)
		switchToCOWMode(str, std::strlen(str));
	else
		switchToSSOMode(str, std::strlen(str));
}

unionString::unionString(const unionString &other)
	: storage_{}
{
	if (other.optimizedType_ == OptimizedType::COW)
	{
		optimizedType_ = OptimizedType::COW;
		storage_.controlCOW = other.storage_.controlCOW;
		addCOWRefCount();
	}
	else if (other.optimizedType_ == OptimizedType::SSO)
	{
		switchToSSOMode(other.storage_.ssoMode.ssoData, other.storage_.ssoMode.ssoSize);
	}
	else
	{
		optimizedType_ = OptimizedType::NonOptimized;
		new (&storage_.heapMode) vector2<char>(
			other.storage_.heapMode.get_data(), other.storage_.heapMode.get_size());
	}
}

unionString &unionString::operator=(const unionString &other)
{
	if (this != &other)
	{
		clear();
		if (other.optimizedType_ == OptimizedType::COW)
		{
			optimizedType_ = OptimizedType::COW;
			storage_.controlCOW = other.storage_.controlCOW;
			addCOWRefCount();
		}
		else if (other.optimizedType_ == OptimizedType::SSO)
		{
			switchToSSOMode(other.storage_.ssoMode.ssoData, other.storage_.ssoMode.ssoSize);
		}
		else
		{
			optimizedType_ = OptimizedType::NonOptimized;
			new (&storage_.heapMode) vector2<char>(
				other.storage_.heapMode.get_data(), other.storage_.heapMode.get_size());
		}
	}

	return *this;
}

unionString::unionString(unionString &&other) noexcept : optimizedType_(other.optimizedType_), storage_{}
{
	if (other.optimizedType_ == OptimizedType::COW)
	{
		storage_.controlCOW = other.storage_.controlCOW;
		new (&other.storage_) Storage();
	}
	else if (other.optimizedType_ == OptimizedType::NonOptimized)
	{
		new (&storage_.heapMode) vector2<char>(std::move(other.storage_.heapMode));
		new (&other.storage_) Storage();
	}
	else
	{
		switchToSSOMode(other.storage_.ssoMode.ssoData, other.storage_.ssoMode.ssoSize);
	}
	other.optimizedType_ = OptimizedType::SSO;
}

unionString unionString::operator+(const unionString &other) const
{
	std::size_t size = this->getSize() + other.getSize() + 1;
	char *newStr = static_cast<char *>(::operator new(size));
	for (size_t i = 0; i < this->getSize(); i++)
	{
		newStr[i] = this->getData()[i];
	}
	for (size_t i = 0; i < other.getSize(); i++)
	{
		*(newStr + this->getSize() + i) = other.getData()[i];
	}
	*(newStr + this->getSize() + other.getSize()) = '\0';
	unionString ret(newStr);
	::operator delete(newStr);
	return ret;
}

char &unionString::operator[](std::size_t index)
{
	if (optimizedType_ == OptimizedType::COW)
	{
		detach();
		return storage_.heapMode[index];
	}
	else if (optimizedType_ == OptimizedType::SSO)
	{
		return storage_.ssoMode.ssoData[index];
	}
	return storage_.heapMode[index];
}

const char &unionString::operator[](std::size_t index) const
{
	if (optimizedType_ == OptimizedType::COW)
	{
		return storage_.controlCOW->getData()[index];
	}
	else if (optimizedType_ == OptimizedType::SSO)
	{
		return storage_.ssoMode.ssoData[index];
	}
	return storage_.heapMode[index];
}

std::size_t unionString::getSize() const
{
	if (optimizedType_ == OptimizedType::COW)
		return storage_.controlCOW->getSize();
	else if (optimizedType_ == OptimizedType::SSO)
		return storage_.ssoMode.ssoSize;
	return storage_.heapMode.get_size();
}

std::size_t unionString::getCapacity() const
{
	if (optimizedType_ == OptimizedType::COW)
		return storage_.controlCOW->getCapacity();
	else if (optimizedType_ == OptimizedType::SSO)
		return SSO_MAX_SIZE;
	return storage_.heapMode.get_capacity();
}

const char *
unionString::getData() const
{
	if (optimizedType_ == OptimizedType::COW)
		return storage_.controlCOW->data;
	else if (optimizedType_ == OptimizedType::SSO)
		return storage_.ssoMode.ssoData;
	return storage_.heapMode.get_data();
}

void unionString::clear()
{
	if (optimizedType_ == OptimizedType::COW && storage_.controlCOW)
	{
		storage_.controlCOW->releaseRefCount();
		new (&storage_) Storage();
	}
	else if (optimizedType_ == OptimizedType::NonOptimized)
	{
		storage_.heapMode.~vector2<char>();
		new (&storage_) Storage();
	}
	else
	{
		storage_.ssoMode.ssoData[0] = '\0';
		storage_.ssoMode.ssoSize = 0;
	}
	optimizedType_ = OptimizedType::SSO;
}

unionString &unionString::operator=(unionString &&other) noexcept
{
	if (this == &other)
		return *this;

	clear();
	optimizedType_ = other.optimizedType_;
	if (other.optimizedType_ == OptimizedType::COW)
	{
		storage_.controlCOW = other.storage_.controlCOW;
		new (&other.storage_) Storage();
	}
	else if (other.optimizedType_ == OptimizedType::NonOptimized)
	{
		new (&storage_.heapMode) vector2<char>(std::move(other.storage_.heapMode));
		new (&other.storage_) Storage();
	}
	else
	{
		switchToSSOMode(other.storage_.ssoMode.ssoData, other.storage_.ssoMode.ssoSize);
	}
	other.optimizedType_ = OptimizedType::SSO;
	return *this;
}

unionString::~unionString()
{
	if (optimizedType_ == OptimizedType::COW)
	{
		storage_.controlCOW->releaseRefCount();
	}
	else if (optimizedType_ == OptimizedType::NonOptimized)
	{
		storage_.heapMode.~vector2<char>();
	}
}
