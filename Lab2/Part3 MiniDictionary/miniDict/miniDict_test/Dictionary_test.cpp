#include "stdafx.h"
#define private public
#include "../miniDict/Dictionary.h"




using namespace std;



BOOST_AUTO_TEST_SUITE(Dictionary_functions)

	CDictionary dictionary;

	BOOST_AUTO_TEST_CASE(check_start_dict_list)
	{
		BOOST_CHECK(dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(check_start_list_of_new_word)
	{
		BOOST_CHECK(dictionary.m_newCollocations.empty());
	}

	BOOST_AUTO_TEST_CASE(load_dict_from_empty_file)
	{
		dictionary.m_dictionaryFile = "empty.txt";
		dictionary.LoadDictionaryFromFile();
		BOOST_CHECK(dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(load_dict_from_nonempty_file)
	{
		dictionary.m_dictionaryFile = "hello.txt";
		dictionary.LoadDictionaryFromFile();
		BOOST_CHECK(!dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(add_new_word)
	{
		dictionary.AddNewWord("dog", "cobaka");
		BOOST_CHECK(!dictionary.m_newCollocations.empty());
		BOOST_CHECK(dictionary.m_dictionaryList.find("dog") != dictionary.m_dictionaryList.end());
	}

	BOOST_AUTO_TEST_CASE(find_existing_word)
	{
		BOOST_CHECK(dictionary.FindWord("dog"));
	}

	BOOST_AUTO_TEST_CASE(find_notexisting_word)
	{
		BOOST_CHECK(!dictionary.FindWord("cat"));
	}

	BOOST_AUTO_TEST_CASE(save_dictionary)
	{
		dictionary.m_dictionaryFile = "empty.txt";
		std::string line;
		dictionary.SaveChanges();
		std::ifstream dic("empty.txt");
		getline(dic, line);
		BOOST_CHECK(!line.empty());
		dic.close();
		std::ofstream clearDic("empty.txt");
	}

	BOOST_AUTO_TEST_CASE(get_word_and_translate)
	{
		BOOST_CHECK(GetPairOfWords("dog=cat").first == "dog"
			&& GetPairOfWords("dog=cat").second == "cat");
	}

BOOST_AUTO_TEST_SUITE_END()
