#include "stdafx.h"
#include "Rational.h"
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return double(m_numerator) / double(m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////

const CRational CRational::operator+ (const CRational& other) const
{
	auto tempNumerator = (m_numerator * other.GetDenominator()) + (other.GetNumerator() * m_denominator);
	auto tempDenominator = m_denominator * other.GetDenominator();

	CRational tempRational(tempNumerator, tempDenominator);
	tempRational.Normalize();
	return tempRational;
}

CRational operator+ (int firstVal, const CRational& secondVal)
{
	auto tempNumerator = (firstVal * secondVal.GetDenominator()) + (secondVal.GetNumerator());

	CRational tempRational(tempNumerator, secondVal.GetDenominator());
	return tempRational;
}

const CRational CRational::operator+ (int const& value) const
{
	auto tempNumerator = (m_numerator + (value * m_denominator));

	CRational tempRational(tempNumerator, m_denominator);
	tempRational.Normalize();
	return tempRational;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator- (const CRational& other) const
{
	auto tempNumerator = (m_numerator * other.GetDenominator()) - (other.GetNumerator() * m_denominator);
	auto tempDenominator = m_denominator * other.GetDenominator();

	CRational tempRational(tempNumerator, tempDenominator);
	tempRational.Normalize();
	return tempRational;
}

CRational operator- (int firstVal, const CRational& secondVal)
{
	auto tempNumerator = (firstVal * secondVal.GetDenominator()) - (secondVal.GetNumerator());

	CRational tempRational(tempNumerator, secondVal.GetDenominator());
	return tempRational;
}

const CRational CRational::operator- (int const& value) const
{
	auto tempNumerator = (m_numerator - (value * m_denominator));

	CRational tempRational(tempNumerator, m_denominator);
	tempRational.Normalize();
	return tempRational;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////

CRational CRational::operator+=(CRational const & other)
{
	m_numerator = GetNumerator() * other.GetDenominator() + other.GetNumerator() * GetDenominator();
	m_denominator = other.GetDenominator() * GetDenominator();

	Normalize();
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////

CRational CRational::operator-=(CRational const & other)
{
	m_numerator = GetNumerator() * other.GetDenominator() - other.GetNumerator() * GetDenominator();
	m_denominator = other.GetDenominator() * GetDenominator();


	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

const CRational CRational::operator *(CRational const& other) const
{
	auto tempNumerator = m_numerator * other.GetNumerator();
	auto tempDenominator = m_denominator * other.GetDenominator();

	CRational tempRational(tempNumerator, tempDenominator);

	tempRational.Normalize();
	return tempRational;
}

CRational operator* (int firstVal, const CRational& secondVal)
{
	return CRational(secondVal.GetNumerator() * firstVal, secondVal.GetDenominator());
}

const CRational CRational::operator* (int const& value) const
{
	auto tempNumerator = m_numerator * value;

	CRational tempRational(tempNumerator, m_denominator);

	//tempRational.Normalize();
	return tempRational;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

const CRational CRational::operator/ (CRational const& other) const
{
	auto tempNumerator = m_numerator * other.GetDenominator();
	auto tempDenominator = m_denominator * other.GetNumerator();

	CRational tempRational(tempNumerator, tempDenominator);

	tempRational.Normalize();
	return tempRational;
}

CRational operator/ (int firstVal, const CRational& secondVal)
{
	return CRational(secondVal.GetDenominator()  * firstVal, secondVal.GetNumerator());
}

const CRational CRational::operator/ (int const& value) const
{
	auto tempDenominator = m_denominator * value;

	CRational tempRational(m_numerator, tempDenominator);

	tempRational.Normalize();
	return tempRational;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////

CRational CRational::operator*= (const CRational& other)
{
	m_numerator *= other.GetNumerator();
	m_denominator *= other.GetDenominator();

	Normalize();
	return *this;
}


CRational CRational::operator*= (int const& value)
{
	m_numerator *= value;

	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational CRational::operator/= (const CRational& other)
{
	m_numerator *= other.GetDenominator();
	m_denominator *= other.GetNumerator();

	Normalize();
	return *this;
}


CRational CRational::operator/= (int const& value)
{
	m_denominator *= value;

	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool CRational::operator== (const CRational& other)
{
	return (GetNumerator() == other.GetNumerator() && GetDenominator() == other.GetDenominator());
}

bool CRational::operator== (int const& value)
{
	return (GetNumerator() == value && GetDenominator() == 1);
}

bool CRational::operator!= (const CRational& other)
{
	return (GetNumerator() != other.GetNumerator() || GetDenominator() != other.GetDenominator());
}

bool CRational::operator!= (int const& value)
{
	return (GetNumerator() != value || GetDenominator() != 1);
}

bool operator== (int const& firstVal, const CRational& secondVal)
{
	return (firstVal == secondVal.GetNumerator()) && (secondVal.GetDenominator() == 1);
}

bool operator!= (int const& firstVal, const CRational& secondVal)
{
	return (firstVal != secondVal.GetNumerator()) || (secondVal.GetDenominator() != 1);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////

bool const CRational::operator< (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) < (other.GetNumerator() * m_denominator));
}

bool const CRational::operator> (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) > (other.GetNumerator() * m_denominator));
}

bool const CRational::operator<= (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) <= (other.GetNumerator() * m_denominator));
}

bool const CRational::operator>= (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) >= (other.GetNumerator() * m_denominator));
}

bool const CRational::operator< (const int& other)
{
	return (m_numerator < (other * m_denominator));
}

bool const CRational::operator> (const int& other)
{
	return (m_numerator > (other * m_denominator));
}

bool const CRational::operator<= (const int& other)
{
	return (m_numerator <= (other * m_denominator));
}

bool const CRational::operator>= (const int& other)
{
	return (m_numerator >= (other * m_denominator));
}

bool const operator< (const int& firstVal, const CRational& secondVal)
{
	return ((firstVal * secondVal.GetDenominator()) < (secondVal.GetNumerator()));
}

bool const operator> (const int& firstVal, const CRational& secondVal)
{
	return ((firstVal * secondVal.GetDenominator()) > (secondVal.GetNumerator()));
}

bool const operator<= (const int& firstVal, const CRational& secondVal)
{
	return ((firstVal * secondVal.GetDenominator()) <= (secondVal.GetNumerator()));
}

bool const operator>= (const int& firstVal, const CRational& secondVal)
{
	return ((firstVal * secondVal.GetDenominator()) >= (secondVal.GetNumerator()));

}
//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

std::ostream & operator <<(std::ostream & stream, CRational const& value)
{
	stream << value.GetNumerator() << '/' << value.GetDenominator();
	return stream;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////

std::istream & operator >>(std::istream & stream, CRational & value)
{
	int tempNumerator;
	int tempDenominator;
	char symbol;
	if ((stream >> tempNumerator) && (stream >> symbol) && (symbol == '/') && (stream >> tempDenominator))
	{
		value = CRational(tempNumerator, tempDenominator);
		return stream;
	}
	// TODO: revert istream on failure
	return stream;
}
