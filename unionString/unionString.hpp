#pragma once

#include "control_block.hpp"
#include "../vector/vector.hpp"
#include <cstddef>
#include <cstring>
enum class OptimizedType
{
	SSO,
	COW,
	NonOptimized
};

static constexpr std::size_t SSO_MAX_SIZE = 15;

union Storage
{
	vector2<char> heapMode;
	struct
	{
		char ssoData[SSO_MAX_SIZE + 1];
		std::size_t ssoSize;
	} ssoMode;
	ControlBlock *controlCOW;
	Storage();

	~Storage();
};

class unionString
{
private:
	OptimizedType optimizedType_;

	Storage storage_;

	void switchToSSOMode(const char *str, std::size_t size);
	void switchToCOWMode(const char *str, std::size_t size, std::size_t capacity = 0);
	void addCOWRefCount();
	void detach();

public:
	unionString();
	unionString(const char *str);

	unionString(const unionString &other);
	unionString &operator=(const unionString &other);

	unionString(unionString &&other) noexcept;
	unionString &operator=(unionString &&other) noexcept;

	unionString operator+(const unionString &other) const;
	unionString &operator+=(const unionString &other);
	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	void clear();

	std::size_t getSize() const;
	std::size_t getCapacity() const;

	const char *getData() const;

	~unionString();
};
