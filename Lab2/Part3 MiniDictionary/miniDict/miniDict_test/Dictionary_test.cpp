#include "stdafx.h"
#include "../miniDict/Dictionary.h"




using namespace std;



BOOST_AUTO_TEST_SUITE(Dictionary_functions)

	CDictionary dictionary;

	BOOST_AUTO_TEST_CASE(start_dict_list_to_be_empty)
	{
		BOOST_CHECK(dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(start_list_of_new_word_to_be_empty)
	{
		BOOST_CHECK(dictionary.m_newCollocations.empty());
	}

	BOOST_AUTO_TEST_CASE(if_load_dictionary_from_empty_file_dict_list_to_be_empty)
	{
		dictionary.m_dictionaryFile = "empty.txt";
		dictionary.LoadDictionaryFromFile();
		BOOST_CHECK(dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(if_load_dictionary_from_nonempty_file_it_should_not_be_empty)
	{
		dictionary.m_dictionaryFile = "hello.txt";
		dictionary.LoadDictionaryFromFile();
		BOOST_CHECK(!dictionary.m_dictionaryList.empty());
	}

	BOOST_AUTO_TEST_CASE(new_word_should_be_insert_into_list_of_new_words_and_into_dictionary_list)
	{
		dictionary.AddNewWord("dog", "cobaka");
		BOOST_CHECK(!dictionary.m_newCollocations.empty());
		BOOST_CHECK(dictionary.m_dictionaryList.find("dog") != dictionary.m_dictionaryList.end());
	}

	BOOST_AUTO_TEST_CASE(can_find_existing_word)
	{
		BOOST_CHECK(dictionary.FindWord("dog"));
	}

	BOOST_AUTO_TEST_CASE(cant_find_notexisting_word)
	{
		BOOST_CHECK(!dictionary.FindWord("cat"));
	}

	BOOST_AUTO_TEST_CASE(save_dictionary_into_empty_doc_it_should_not_be_empty)
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

	BOOST_AUTO_TEST_CASE(must_return_left_and_right_parts)
	{
		BOOST_CHECK(GetPairOfWords("dog=cat").first == "dog"
			&& GetPairOfWords("dog=cat").second == "cat");
	}

BOOST_AUTO_TEST_SUITE_END()
