#include "stdafx.h"
#include "iterator.h"


//template<typename T>
//my_iterator<T>::my_iterator(Node<T> * someNode)
//{
//	value = someNode;
//}
//
//template<typename T>
//my_iterator<T>::~my_iterator()
//{
//}

//template<typename T>
//void my_iterator<T>::operator++()
//{
//	this = next;
//}

template<typename T>
void my_iterator<T>::operator--()
{
	this = previous;
}

//template<typename T>
//bool Base_Iter<T>::operator==(Node<T> * other) const
//{
//	return ptr == other;
//}

template<typename T>
bool my_iterator<T>::operator!=(my_iterator<T> const & other) const
{
	return ptr != other->ptr;
}

template<typename T>
r_iterator<T>::r_iterator(Node<T> * someNode)
{
	value = someNode;
}

template<typename T>
r_iterator<T>::~r_iterator()
{
}

template<typename T>
inline void r_iterator<T>::operator++()
{
	this = previous;
}

template<typename T>
inline void r_iterator<T>::operator--()
{
	this = next;
}

template<typename T>
bool r_iterator<T>::operator==(r_iterator<T> const & other) const
{
	return value == other->value;
}

template<typename T>
bool r_iterator<T>::operator!=(r_iterator<T> const & other) const
{
	return value != other->value;
}
