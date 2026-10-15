#include "vector.hpp"
#include <new>
#include <utility>

template <typename T>
vector2<T>::vector2()
	: size_(0), capacity_(2), data_(static_cast<T *>(::operator new[](capacity_ * sizeof(T))))
{
}

template <typename T>
vector2<T>::vector2(std::initializer_list<T> list)
{
	if (list.size() == 0)
	{
		size_ = 0;
		capacity_ = 2;
		data_ = static_cast<T *>(::operator new[](capacity_ * sizeof(T)));
		return;
	}
	size_ = list.size();
	capacity_ = size_;

	data_ = static_cast<T *>(::operator new[](capacity_ * sizeof(T)));
	for (std::size_t i = 0; i < size_; ++i)
		new (data_ + i) T(list.begin()[i]);
}

template <typename T>
vector2<T>::vector2(size_t size) : size_(size), capacity_(size_ > 0 ? size_ : 2), data_(static_cast<T *>(::operator new[](capacity_ * sizeof(T))))
{
	for (std::size_t i = 0; i < size; ++i)
		new (data_ + i) T();
	size_ = size;
}

template <typename T>
vector2<T>::vector2(const vector2<T> &obj)
	: size_(obj.size_), capacity_(obj.capacity_ > 0 ? obj.capacity_ : 2),
	  data_(static_cast<T *>(::operator new[](capacity_ * sizeof(T))))
{
	for (std::size_t i = 0; i < size_; ++i)
		new (data_ + i) T(obj.data_[i]);
}

template <typename T>
vector2<T>::vector2(vector2<T> &&rhv) noexcept
	: size_(rhv.size_), capacity_(rhv.capacity_), data_(rhv.data_)
{
	rhv.data_ = nullptr;
	rhv.size_ = 0;
	rhv.capacity_ = 0;
}

template <typename T>
T &vector2<T>::operator[](std::size_t index)
{
	return data_[index];
}

template <typename T>
const T &vector2<T>::operator[](std::size_t index) const
{
	return data_[index];
}

template <typename T>
void vector2<T>::push_back(const T &value)
{
	if (size_ == capacity_)
	{
		std::size_t new_capacity = (capacity_ == 0) ? 2 : capacity_ * 2;
		T *new_data = static_cast<T *>(::operator new[](new_capacity * sizeof(T)));
		for (std::size_t i = 0; i < size_; ++i)
		{
			new (new_data + i) T(data_[i]);
			data_[i].~T();
		}
		::operator delete[](data_);
		data_ = new_data;
		capacity_ = new_capacity;
	}
	new (data_ + size_) T(value);
	++size_;
}

template <typename T>
void vector2<T>::push_back(T &&value)
{
	if (size_ == capacity_)
	{
		std::size_t new_capacity = (capacity_ == 0) ? 2 : capacity_ * 2;
		T *new_data = static_cast<T *>(::operator new[](new_capacity * sizeof(T)));
		for (std::size_t i = 0; i < size_; ++i)
		{
			new (new_data + i) T(std::move(data_[i]));
			data_[i].~T();
		}
		::operator delete[](data_);
		data_ = new_data;
		capacity_ = new_capacity;
	}
	new (data_ + size_) T(std::move(value));
	++size_;
}

template <typename T>
void vector2<T>::grow_and_push(const T &value)
{
	push_back(value);
}

template <typename T>
void vector2<T>::grow_and_push(T &&value)
{
	push_back(std::move(value));
}

template <typename T>
vector2<T> &vector2<T>::operator=(const vector2<T> &rhv)
{
	if (this == &rhv)
		return *this;

	destroy_elements();
	if (data_ != nullptr)
		::operator delete[](data_);

	capacity_ = (rhv.capacity_ > 0) ? rhv.capacity_ : 2;
	data_ = static_cast<T *>(::operator new[](capacity_ * sizeof(T)));
	size_ = rhv.size_;
	for (std::size_t i = 0; i < size_; ++i)
		new (data_ + i) T(rhv.data_[i]);
	return *this;
}

template <typename T>
vector2<T> &vector2<T>::operator=(vector2<T> &&rhv) noexcept
{
	if (this == &rhv)
		return *this;

	destroy_elements();
	if (data_ != nullptr)
		::operator delete[](data_);

	size_ = rhv.size_;
	capacity_ = rhv.capacity_;
	data_ = rhv.data_;
	rhv.data_ = nullptr;
	rhv.size_ = 0;
	rhv.capacity_ = 0;
	return *this;
}

template <typename T>
vector2<T> vector2<T>::operator+(const vector2<T> &other) const
{
	vector2<T> result;
	result.reserve(size_ + other.size_);
	for (std::size_t i = 0; i < size_; ++i)
		result.push_back(data_[i]);
	for (std::size_t i = 0; i < other.size_; ++i)
		result.push_back(other.data_[i]);
	return result;
}
template <typename T>
vector2<T> vector2<T>::operator-(const vector2<T> &other) const
{
	vector2<T> res;
	std::unordered_set<T> values;

	for (size_t i = 0; i < other.get_size(); i++)
		values.insert(other[i]);
	for (size_t i = 0; i < get_size(); i++)
	{
		if (!values.count((*this)[i]))
			res.push_back((*this)[i]);
	}
	return res;
}

template <typename T>
vector2<T> &vector2<T>::operator+=(const vector2<T> &other)
{
	*this = *this + other;
	return *this;
}

template <typename T>
vector2<T> &vector2<T>::operator-=(const vector2<T> &other)
{
	*this = *this - other;
	return *this;
}

template <typename T>
bool vector2<T>::operator==(const vector2<T> &other) const
{
	if (this == &other)
		return true;
	if (get_size() != other.get_size())
		return false;
	for (size_t i = 0; i < get_size(); i++)
	{
		if (at(i) != other.at(i))
			return false;
	}
	return true;
}

template <typename T>
bool vector2<T>::operator!=(const vector2<T> &other) const
{
	return !(*this).operator==(other);
}
template <typename T>
void vector2<T>::reserve(std::size_t new_capacity)
{
	if (new_capacity <= capacity_)
		return;
	T *new_data = static_cast<T *>(::operator new[](new_capacity * sizeof(T)));
	for (std::size_t i = 0; i < size_; ++i)
	{
		new (new_data + i) T(std::move(data_[i]));
		data_[i].~T();
	}
	::operator delete[](data_);
	data_ = new_data;
	capacity_ = new_capacity;
}

template <typename T>
void vector2<T>::resize(std::size_t new_size)
{
	if (new_size < size_)
	{
		for (std::size_t i = new_size; i < size_; ++i)
			data_[i].~T();
	}
	else if (new_size > size_)
	{
		if (new_size > capacity_)
			reserve(new_size);
		for (std::size_t i = size_; i < new_size; ++i)
			new (data_ + i) T();
	}
	size_ = new_size;
}
template <typename T>
T &vector2<T>::at(std::size_t index)
{
	if (index >= size_)
		throw std::out_of_range("Index out of range");
	return data_[index];
}

template <typename T>
const T &vector2<T>::at(std::size_t index) const
{
	if (index >= size_)
		throw std::out_of_range("Index out of range");
	return data_[index];
}

template <typename T>
std::size_t vector2<T>::get_capacity() const
{
	return capacity_;
}

template <typename T>
std::size_t vector2<T>::get_size() const
{
	return size_;
}

template <typename T>
T *vector2<T>::get_data()
{
	return data_;
}

template <typename T>
const T *vector2<T>::get_data() const
{
	return data_;
}

template <typename T>
void vector2<T>::clear() noexcept
{
	destroy_elements();
}

template <typename T>
void vector2<T>::destroy_elements() noexcept
{
	for (std::size_t i = 0; i < size_; ++i)
		data_[i].~T();
	size_ = 0;
}

template <typename T>
vector2<T>::~vector2()
{
	if (data_ != nullptr)
	{
		destroy_elements();
		::operator delete[](data_);
		data_ = nullptr;
	}
}
