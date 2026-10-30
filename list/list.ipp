#include "list.hpp"

template <typename T>
ListNode<T>::ListNode(T x) : val(x), next(nullptr), prev(nullptr) {}

template <typename T>
ListNode<T>::ListNode() : ListNode(T()) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::initializer_list<T> &list) : head(nullptr), tail(nullptr)
{
	for (const T &value : list)
	{
		push_back(value);
	}
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(size_t size, const T &value) : head(nullptr), tail(nullptr)
{
	for (size_t i = 0; i < size; ++i)
		push_back(value);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &other) : head(nullptr), tail(nullptr)
{
	for (ListNode<T> *current = other.head; current != nullptr; current = current->next)
		push_back(current->val);
}

template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other)
{
	if (this != &other)
	{
		clear();
		for (ListNode<T> *current = other.head; current != nullptr; current = current->next)
			push_back(current->val);
	}
	return *this;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T> &&other) noexcept
	: head(other.head), tail(other.tail)
{
	other.head = nullptr;
	other.tail = nullptr;
}

template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(DoublyLinkedList<T> &&other) noexcept
{
	if (this != &other)
	{
		clear();
		this->head = other.head;
		this->tail = other.tail;
		other.head = nullptr;
		other.tail = nullptr;
	}
	return *this;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T &value)
{
	if (!head)
	{
		head = new ListNode<T>(value);
		tail = head;
		return;
	}

	ListNode<T> *newNode = new ListNode<T>(value);
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
}

template <typename T>
T &DoublyLinkedList<T>::operator[](int index)
{
	ListNode<T> *current = head;
	for (int i = 0; i < index && current != nullptr; ++i)
		current = current->next;
	return current->val;
}

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
	if (!tail)
		return;

	ListNode<T> *tmp = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	else
		head = nullptr;
	delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T &value)
{
	if (!head)
	{
		head = new ListNode<T>(value);
		tail = head;
		return;
	}
	ListNode<T> *newNode = new ListNode<T>(value);
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
	if (!head)
		return;

	ListNode<T> *ttailmp = head;
	head = head->next;
	if (head)
		head->prev = nullptr;
	else
		tail = nullptr;
	delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
	if (index == 0)
	{
		pop_front();
		return;
	}
	ListNode<T> *current = head;
	for (int i = 0; i < index && current != nullptr; ++i)
		current = current->next;
	if (current)
	{
		if (current->prev)
			current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
		if (current == tail)
			tail = current->prev;
		delete current;
	}
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	while (head)
	{
		ListNode<T> *tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::insert(const T &value, int index)
{
	if (index == 0)
	{
		push_front(value);
		return;
	}
	ListNode<T> *current = head;
	for (int i = 0; i < index && current != nullptr; ++i)
		current = current->next;
	if (current)
	{
		ListNode<T> *newNode = new ListNode<T>(value);
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;
	}
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}
