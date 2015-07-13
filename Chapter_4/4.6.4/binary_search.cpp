#include <iostream>
#include <math.h>
#include "binary_search.h"

int main(void)
{
	using namespace std;
	
	int sizes[] = {3, 10, 15, 50, 100, 1000, 1<<10, 10000, 1<<16, 100000, 1<<20};
	
	for (const auto &size : sizes)
	{
		int * items = new int[size];
		for (int i=0; i<size; i++)
			items[i] = i;
		
		cout << "computing the average number of calls for an array of 2^" << log2(size) << " items..." << endl;
		
		double call_count = 0;
		
		for (int i=0; i<size; i++)
			binary_search(items, i, 0, i, call_count);
		
		call_count /= size;
		
		cout << "\t-> " << call_count << " calls on average\n" << endl;
		
		delete [] items;
	}

	cout << endl;

	return 0;
}
