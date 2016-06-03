#pragma once
#include "iterator.h"

template <typename T>
class CMyList
{
public:
	CMyList<T>()
		: m_size(0)
	{}
	~CMyList<T>()
	{
		Node<T> * first = m_begin;
		Node<T> * second = m_begin->next;
		if (first)
		{
			delete first;
			while (second)
			{
				first = second;
				second = second->next;
				delete first;
			}
		}
	}
	size_t GetSize();

	void PushBack(T const& value)
	{

		++m_size;
		Node<T> * newNode = new Node<T>(value);
		if (!m_begin)
		{
			m_begin = newNode;
			m_end = newNode;
		}
		else
		{
			m_end->next = newNode;
			newNode->previous = m_end;
			m_end = newNode;
		}
	}
	void PushFront(T const& value)
	{
		++m_size;
		Node<T> * newNode = new Node<T>(value);
		if (!m_begin)
		{
			m_begin = newNode;
			m_end = newNode;
		}
		else
		{
			m_begin->previous = newNode;
			newNode->next = m_begin;
			m_begin = newNode;
		}
	}

	void Insert(Base_Iter<T> const& iter, T const& val)
	{
	Node<T> * newNode = new Node<T>(val);
	if (iter == m_begin)
	{
		PushFront(val);
	}
	else if (iter == nullptr)
	{
		PushBack(val);
	}
	else
	{
		auto node = iter.GetNode();
		newNode->previous = node->previous;
		newNode->next = node;
		node->previous->next = newNode;
		node->previous = newNode;
	}
}
	void Delete(Node<T> * iter);

	my_iterator<T> begin()
	{
		return my_iterator<T>(m_begin);
	}

	my_iterator<T> end()
	{
		return my_iterator(m_end->next);
	}

	r_iterator<T> rbegin()
	{
		return my_iterator(m_end);
	}

	r_iterator<T> rend()
	{
		return my_iterator(m_begin->previous);
	}

private:
	size_t m_size;

	Node<T> * m_begin = nullptr;
	Node<T> * m_end = nullptr;
	
};

