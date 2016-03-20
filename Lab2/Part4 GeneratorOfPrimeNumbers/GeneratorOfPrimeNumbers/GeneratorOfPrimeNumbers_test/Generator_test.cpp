#include "stdafx.h"
#include "../GeneratorOfPrimeNumbers/Generator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Generator_of_prime_numbers_function)

BOOST_AUTO_TEST_CASE(empty_set_when_wrong_range_value)
{
	auto testSet = CGenerator::GetSetOfPrimeNumbers(1);
	BOOST_CHECK(testSet.empty());
	testSet = CGenerator::GetSetOfPrimeNumbers(100000001);
	BOOST_CHECK(testSet.empty());
}

BOOST_AUTO_TEST_CASE(set_of_one_element_when_min_range)
{
	auto testSet = CGenerator::GetSetOfPrimeNumbers(2);
	BOOST_CHECK(testSet.size() == 1);
}

BOOST_AUTO_TEST_CASE(set_of_few_element_when_true_range)
{
	auto testSet = CGenerator::GetSetOfPrimeNumbers(7);
	BOOST_CHECK(testSet.size() == 4);
}

BOOST_AUTO_TEST_SUITE_END()