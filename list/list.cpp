#include "list.hpp"

template <typename T>
ListNode<T>::ListNode(T x) : val(x), next(nullptr), prev(nullptr) {}

template <typename T>
ListNode<T>::ListNode() : ListNode(T()) {}

template <typename T>
void ListNode<T>::push_back(const ListNode<T> &node)
{
	ListNode<T> *newNode = new ListNode<T>(node.val);
	newNode->prev = this;
	if (this->next)
	{
		newNode->next = this->next;
		this->next->prev = newNode;
	}
	this->next = newNode;
	newNode->next = nullptr;
}


