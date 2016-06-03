#pragma once
//#include "MyList.h" 

template <typename T>
struct Node
{
	Node()
	{};
	Node(T const& val)
		:value(std::move(val))
	{};
	Node(Node<T> const& other)
		: value(other->value)
		, previous(other->previous)
		, next(other->next)
	{	};
	T value;
	Node * previous = nullptr;
	Node * next = nullptr;
};

template <typename T>
class Base_Iter
{
public:
	Base_Iter()
	{}
	~Base_Iter() = default;
	bool operator == (Node<T> * other) const
	{
		return ptr == other;
	}
	Node<T> * GetNode()
	{
		return ptr;
	}
protected:
	Node<T> * ptr;
};

template <typename T>
class r_iterator;

template <typename T>
class my_iterator : public Base_Iter<T>
{
public:
	my_iterator<T>(Node<T> * someNode)
	{
		ptr = someNode;
	}

	~my_iterator() = default;

	void operator= (Node<T> * other)
	{
		ptr = other;
	}

	void my_iterator<T>::operator ++ ()
	{
		ptr = ptr->next;
	}

	void operator-- ();
	bool operator == (Node<T> * other) const;
	bool operator != (my_iterator const& other) const;

};

template <typename T>
class r_iterator : public Node<T>
{
	r_iterator(Node<T> * someNode);
	~r_iterator();

	void operator++ () override;
	void operator-- () override;
	bool operator == (r_iterator const& other) const override;
	bool operator != (r_iterator const& other) const override;
};


