
#include "stdafx.h"
#include "../../FindAndReplace/FindAndReplace/Replace.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

BOOST_AUTO_TEST_CASE(give_empty_string)
{
	string subject = "";
	string search = "";
	string replace = "";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str.empty());
}

BOOST_AUTO_TEST_CASE(give_string_without_replace)
{
	string subject = "mama";
	string search = "";
	string replace = "";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(subject == str);
}

BOOST_AUTO_TEST_CASE(give_string_and_replace_ma_on_cat)
{
	string subject = "mama";
	string search = "ma";
	string replace = "cat";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "catcat");
}

BOOST_AUTO_TEST_CASE(give_string_and_replace_ma_on_mama)
{
	string subject = "mama";
	string search = "ma";
	string replace = "mama";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "mamamama");
}

BOOST_AUTO_TEST_CASE(give_empty_search_string)
{
	string subject = "mama";
	string search = "";
	string replace = "mama";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "mama");

}

BOOST_AUTO_TEST_CASE(give_empty_replace_string)
{
	string subject = "mama";
	string search = "ma";
	string replace = "";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str.empty());

}

BOOST_AUTO_TEST_CASE(give_string_and_replace_ma_on_mama_four_times)
{
	string subject = "mamamama";
	string search = "ma";
	string replace = "mama";

	string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "mamamamamamamama");

}
BOOST_AUTO_TEST_SUITE_END()
