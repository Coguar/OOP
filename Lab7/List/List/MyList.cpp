#include "stdafx.h"
#include "MyList.h"


//template<typename T>
//CMyList<T>::CMyList<T>()
//	:m_size(0)
//{
//	m_begin->next = m_end;
//	m_end->previous = m_begin;
//}

//template<typename T>
//CMyList<T>::~CMyList<T>()
//{
//	Node<T> * first = m_begin;
//	Node<T> * second = m_begin->next;
//	if (first)
//	{
//		delete first;
//		while (second)
//		{
//			first = second;
//			second = second->next;
//			delete first;
//		}
//	}
//}

template<typename T>
size_t CMyList<T>::GetSize()
{
	return m_size;
}

//template<typename T>
//void CMyList<T>::PushBack(T const& value)
//{
//	++m_size;
//	Node<T> newNode = new Node<T>(value);
//	newNode->previous = end->previous;
//	newNode->next = end;
//	end->previous->next = newNode;
//	end->previous = newNode;
//}

//template<typename T>
//void CMyList<T>::PushFront(T const& value)
//{
//	++m_size;
//	Node<T> newNode = new Node<T>(value);
//	begin->previous = newNode;
//	newNode->next = begin->previous;
//	begin = newNode;
//}

//template<typename T>
//void CMyList<T>::Insert(Node<T> * iter, T const& val)
//{
//	Node<T> newNode = new Node<T>(val);
//	if (iter == m_begin)
//	{
//		PushFront(val);
//	}
//	else if (iter == m_end)
//	{
//		PushBack(val);
//	}
//	else
//	{
//		newNode->previous = iter->previous;
//		newNode->next = iter;
//		iter->previous->next = newNode;
//		iter->previous = newNode;
//	}
//}

template<typename T>
void CMyList<T>::Delete(Node<T>* iter)
{
	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;
	delete iter;
}

//template<typename T>
//my_iterator<T> CMyList<T>::begin()
//{
//	return my_iterator(m_begin);
//}
//
//template<typename T>
//my_iterator<T> CMyList<T>::end()
//{
//	return my_iterator(m_end);
//}
//
//template<typename T>
//r_iterator<T> CMyList<T>::rbegin()
//{
//	return r_iterator(m_end->previous);
//}
//
//template<typename T>
//r_iterator<T> CMyList<T>::rend()
//{
//	return r_iterator(m_begin);
//}
