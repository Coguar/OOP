#include "stdafx.h"
#include "Generator.h"

set<size_t> CGenerator::GetSetOfPrimeNumbers(size_t range)
{
	set<size_t> primeNumbersSet;
	if (range <= MAX_RANGE && range >= MIN_RANGE)
	{
		vector<bool> sieve;
		PrepareInitialVector(sieve, range);
		MarkComplexNumbers(sieve, range);
		FillInSet(primeNumbersSet, sieve, range);
	}
	return primeNumbersSet;
}


void CGenerator::PrepareInitialVector(vector<bool> & sieve, size_t const& range)
{
	sieve = vector<bool>(range + 1, true);
	sieve[0] = false;
	sieve[1] = false;
}

void CGenerator::MarkComplexNumbers(vector<bool> & sieve, size_t const& range)
{
	for (size_t i = 2; i * i <= range; ++i)
	{
		if (sieve[i])
		{
			for (size_t j = i * i; j <= range; j += i)
			{
				if (sieve[j])
				{
					sieve[j] = false;
				}
			}
		}
	}
}

void CGenerator::FillInSet(set<size_t> & primeNumbersSet, vector<bool> const& sieve, size_t const& range)
{
	for (size_t number = 0; number <= range; ++number)
	{
		if (sieve[number])
		{
			primeNumbersSet.insert(number);
		}
	}
}
