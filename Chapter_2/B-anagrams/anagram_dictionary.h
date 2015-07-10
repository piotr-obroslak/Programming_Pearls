#include<iostream>
#include<algorithm>
#include<list>
#include<map>

class anagram_dictionary
{
public:
    inline void add(const std::string &str)
    {
	m_dictionary[make_signature(str)].push_back(str);
    }

    inline void print(void) const
    {
	if (m_dictionary.empty())
	{
	    std::cout << "the dictionary is empty" << std::endl;
	}
	
	for (const auto &item : m_dictionary)
	{
	    const auto &signature = item.first;
	    const auto &anagrams = item.second;
	    std::cout << "anagrams of " << *anagrams.begin() << '(' << signature<< ')' << " are:\n";
	    
	    for (const auto &a : anagrams)
		std::cout << a << "\n";
	    
	    std::cout << std::endl;
	}
    }

protected:
    std::string make_signature(const std::string &str)
    {
	auto signature = str;

	for (auto &c : signature)
	    c = tolower(c);

	std::sort(signature.begin(), signature.end());

	return std::move(signature);
    }

protected:
    std::map<std::string, std::list<std::string>> m_dictionary;
};
