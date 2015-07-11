#include<iostream>
#include "anagram_dictionary.h"

static void print_anagrams(const anagram_dictionary &dict)
{
	using namespace std;

	auto count = 0;

	for (const auto &item : dict)
	{
		const auto &signature = item.first;
		const auto &anagrams = item.second;

		cout << "anagrams of " << *anagrams.begin() << " (sgn=" << signature<< ")" << " are:\n";

		for (const auto &a : anagrams)
			cout << a << "\n";

		cout << "\n";

		count++;
	}

	if (count == 0)
		cout << "Looks like the dictionary is empty...\n";

	cout << endl;
}

int main(int argc, char*argv[])
{
	anagram_dictionary dict;
	
	for (int i=1; i<argc; i++)
		dict.add(argv[i]);
	
	print_anagrams(dict);

	return 0;
}
