#ifndef _ANAGRAM_DICTIONARY_H_
#define _ANAGRAM_DICTIONARY_H_

#include <algorithm>
#include <list>
#include <map>

typedef std::string word_storage;
typedef std::list<word_storage> word_collection;
typedef std::map<word_storage, word_collection> raw_anagram_dictionary;

class anagram_dictionary
	: protected raw_anagram_dictionary
{
public:
	void add(const word_storage &word) {
		raw_anagram_dictionary::operator[](make_signature(word)).push_back(word);
	}
	
	const_iterator begin() const {
		return raw_anagram_dictionary::begin();
	}
	
	const_iterator end() const {
		return raw_anagram_dictionary::end();
	}

protected:
	word_storage make_signature(const word_storage &word) const
	{
		auto signature = word;

		for (auto &c : signature)
			c = tolower(c);

		std::sort(signature.begin(), signature.end());

		return std::move(signature);
	}
};

#endif
