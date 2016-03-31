#pragma once
#include <set>
#include <vector>

using namespace std;

class CGenerator
{
public:
	static set<size_t> GetSetOfPrimeNumbers(size_t range);

private:
	static void PrepareInitialVector(vector<bool> & sieve, size_t const& range);

	static void MarkComplexNumbers(vector<bool> & sieve, size_t const& range);

	static void FillInSet(set<size_t> & primeNumbersSet, vector<bool> const& sieve, size_t const& range);

	static const size_t MAX_RANGE = 100000000;
	static const size_t MIN_RANGE = 2;
};