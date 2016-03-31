
#include "stdafx.h"
#include "../../FindAndReplace/FindAndReplace/Replace.h"
#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

	BOOST_AUTO_TEST_CASE(return_empty_string_from_empty_subject_string)
	{
		string subject = "";
		string search = "cat";
		string replace = "dog";

		string str = FindAndReplace(subject, search, replace);
		BOOST_CHECK(str.empty());
	}

	BOOST_AUTO_TEST_CASE(replace_search_string_on_replace_string)
	{
		string subject = "mama";
		string search = "ma";
		string replace = "cat";

		string str = FindAndReplace(subject, search, replace);
		std::cout << str << std::endl;
		BOOST_CHECK(str == "catcat");
	}

	BOOST_AUTO_TEST_CASE(return_source_string_if_search_string_is_empty)
	{
		string subject = "mama";
		string search = "";
		string replace = "mama";

		string str = FindAndReplace(subject, search, replace);
		BOOST_CHECK(str == "mama");

	}

	BOOST_AUTO_TEST_CASE(delete_search_string_from_source_string_if_replace_string_is_empty)
	{
		string subject = "mamaf";
		string search = "ma";
		string replace = "";

		string str = FindAndReplace(subject, search, replace);
		std::cout << "string = " << str << std::endl;
		BOOST_CHECK_EQUAL(str, "f");

	}

	BOOST_AUTO_TEST_CASE(replace_search_string_on_double_search_string)
	{
		string subject = "mamamama";
		string search = "ma";
		string replace = "mama";

		
		string str = FindAndReplace(subject, search, replace);
		std::cout << str << std::endl;

		BOOST_CHECK(str == "mamamamamamamama");

	}

	BOOST_AUTO_TEST_CASE(return_source_string_if_serch_string_longer_then_source)
	{
		string subject = "cat";
		string search = "crow";
		string replace = "dog";


		string str = FindAndReplace(subject, search, replace);
		std::cout << str << std::endl;

		BOOST_CHECK_EQUAL(str, subject);

	}

BOOST_AUTO_TEST_SUITE_END()
