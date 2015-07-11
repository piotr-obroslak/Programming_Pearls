#include "anagram_dictionary.h"

int main(int argc, char*argv[])
{
	anagram_dictionary dict;

	for (int i=1; i<argc; i++)
		dict.add(argv[i]);

	dict.print();

	return 0;
}
