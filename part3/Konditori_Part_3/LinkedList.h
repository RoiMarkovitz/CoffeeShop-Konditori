#ifndef __LinkedList_H
#define __LinkedList_H
#include <ostream>

template <class T>
class Node
{
	T data;
	Node* next;
	Node(const T data, Node* prev = nullptr);
	template <class T> friend class LinkedList;
};

template <class T>
class LinkedList
{
	Node<T>* head, * tail;
	std::ostream& print(std::ostream& os) const;
public:
	LinkedList();
	~LinkedList();
	void add(const T data);
	T* get(const T data) const;
	void remove(const T data);
	void clear();
	const LinkedList& operator=(const LinkedList& other);
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& list)
	{
		return list.print(os);
	}
};

template<class T>
inline Node<T>::Node(const T data, Node<T>* prev) : data(data), next(nullptr)
{
	if (prev)
		prev->next = this;
}

template<class T>
inline std::ostream& LinkedList<T>::print(std::ostream& os) const
{
	Node<T>* pn = head;

	while (pn) {
		os << pn->data;
		pn = pn->next;
	}
	return os;
}

template<class T>
inline void LinkedList<T>::clear()
{
	if (head == nullptr)
		return;

	Node<T>* pn = head;

	while (pn)
	{
		Node<T>* next = pn->next;
		delete pn;
		pn = next;
	}
	head = tail = nullptr;
}

template<class T>
inline LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
inline void LinkedList<T>::add(const T data)
{
	if (head)
	{
		Node<T>* pn = new Node<T>(data, tail);
		tail = pn;
	}
	else
	{
		Node<T>* pn = new Node<T>(data);
		head = tail = pn;
	}
}

template<class T>
inline T* LinkedList<T>::get(const T data) const
{
	Node<T>* pn = head;

	while (pn)
	{
		if (pn->data == data)
			return &pn->data;

		pn = pn->next;
	}
	return nullptr;
}

template<class T>
inline void LinkedList<T>::remove(const T data)
{
	Node<T>* pn = head;
	Node<T>* prev = head;

	while (pn)
	{
		Node<T>* next = pn->next;

		if (pn->data == data)
		{
			if (pn == head)
			{
				if (head == tail)
					head = tail = nullptr;
				else
					head = head->next;
			}
			else if (pn == tail)
			{
				prev->next = nullptr;
				tail = prev;
			}
			else
			{
				prev->next = next;
			}
			delete pn;
			return;
		}
		prev = pn;
		pn = next;
	}
}
template<class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	clear();
	Node<T>* oHead = other.head;
	while (oHead != nullptr)
	{
		add(oHead->data);
		oHead = oHead->next;
	}

	return *this;
}
#endif //__LinkedList_H