#pragma once

#include <cstddef>
#include <initializer_list>

template <typename T>
struct ListNode
{
	T val;
	ListNode<T> *next;
	ListNode<T> *prev;

	explicit ListNode(T value);
	ListNode();
};

template <typename T>
class DoublyLinkedList
{
public:
	using value_type = T;
	using size_type = std::size_t;

	DoublyLinkedList();
	DoublyLinkedList(const std::initializer_list<T> &values);
	DoublyLinkedList(size_type count, const T &value);

	DoublyLinkedList(const DoublyLinkedList &other);
	DoublyLinkedList(DoublyLinkedList &&other) noexcept;
	DoublyLinkedList &operator=(const DoublyLinkedList &other);
	DoublyLinkedList &operator=(DoublyLinkedList &&other) noexcept;

	~DoublyLinkedList();

	void push_back(const T &value);
	void push_front(const T &value);
	void pop_back();
	void pop_front();
	void insert(const T &value, int index);
	void remove(int index);

	T &operator[](int index);

	void clear();

private:
	ListNode<T> *head;
	ListNode<T> *tail;
};

#include "list.ipp"
