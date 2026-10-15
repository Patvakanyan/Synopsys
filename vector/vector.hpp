#pragma once
#include <cstddef>
#include <utility>
#include <stdexcept>
#include <unordered_set>
#include <initializer_list>
template <typename T>
class vector2
{
private:
	std::size_t size_;
	std::size_t capacity_;
	T *data_;

public:
	vector2();
	vector2(std::initializer_list<T> list);
	vector2(size_t size);
	vector2(const vector2<T> &obj);
	vector2(vector2<T> &&rhv) noexcept;
	vector2 &operator=(vector2<T> &&rhv) noexcept;
	vector2 &operator=(const vector2<T> &rhv);
	~vector2();

	bool operator==(const vector2<T> &other) const;
	bool operator!=(const vector2<T> &other) const;

	vector2<T> &operator+=(const vector2<T> &other);
	vector2<T> operator+(const vector2<T> &other) const;

	vector2<T> operator-(const vector2<T> &other) const;
	vector2<T> &operator-=(const vector2<T> &other);

	void reserve(std::size_t new_capacity);
	void resize(std::size_t new_size);
	T &operator[](std::size_t index);
	const T &operator[](std::size_t index) const;

	T &at(std::size_t index);
	const T &at(std::size_t index) const;



	void push_back(const T &value);
	void push_back(T &&value);
	void grow_and_push(const T &value);
	void grow_and_push(T &&value);
	void destroy_elements() noexcept;

	std::size_t get_size() const;
	std::size_t get_capacity() const;
	T *get_data();
	const T *get_data() const;
	void clear() noexcept;
};

#include "vector.ipp"
