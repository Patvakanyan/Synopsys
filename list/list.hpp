#pragma once

#include <initializer_list>


template <typename T>
struct ListNode {
	T val;
	ListNode *next;
	ListNode *prev;
	ListNode(T x);
	ListNode();
};


template <typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();

	DoublyLinkedList(const std::initializer_list<T> &list);

	DoublyLinkedList(size_t size, const T &value);
	DoublyLinkedList(const DoublyLinkedList<T> &other);
	DoublyLinkedList(DoublyLinkedList<T> &&other) noexcept;
	DoublyLinkedList<T> &operator=(const DoublyLinkedList<T> &other);
	DoublyLinkedList<T> &operator=(DoublyLinkedList<T> &&other) noexcept;

	void push_back(const T &value);
	void pop_back();
	void push_front(const T &value);
	void pop_front();
	void insert(const T &value, int index);
	void remove(int index);
	T &operator[](int index);

	~DoublyLinkedList();
private:
	ListNode<T> *head;
	ListNode<T> *tail;
};
