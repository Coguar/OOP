#pragma once

#include <new>
#include <algorithm>

template <typename T>
class CMyArray
{
public:
	void Append(const T & value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(1u, GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T *newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// ������������ ����� value �� ������ newItemLocation
				new (newEnd)T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// ������������� �� ������������� ������ ��������� ���������
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;

		}
		else // has free space
		{

		}
	}

	size_t GetSize()const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity()const
	{
		return m_endOfCapacity - m_begin;
	}
	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}
private:

	static void DeleteItems(T *begin, T *end)
	{
		// ��������� ������ ��������
		DestroyItems(begin, end);
		// ����������� ������� ������ ��� �� ��������
		RawDealloc(begin);
	}
	// �������� �������� �� �������� ������� � to, ���������� newEnd
	static void CopyItems(T *begin, T *end, T * const dstBegin, T * & dstEnd)
	{
		for (dstEnd = dstBegin; begin != end; ++begin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd)T(*begin);
		}
	}

	static void DestroyItems(T *from, T *to)
	{
		// dst - ����� ������, ��� ��������������� �������� ���� ��������� ����������
		// to - ������ ������������������ ������
		for (; to != from; )
		{
			--to;
			// ���� �������� ���������� ��� ���������� ���� T
			to->~T();
		}
	}

	static T *RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T *p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T *p)
	{
		free(p);
	}

private:
	T *m_begin = nullptr;
	T *m_end = nullptr;
	T *m_endOfCapacity = nullptr;
};