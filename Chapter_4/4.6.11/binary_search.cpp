#include <iostream>
#include "binary_search.h"

int main(void)
{
	using namespace std;
	
	int items[] = {1,2,3,7,12,705, 706};
	int values[] = {1,2,3,7,12,705, 706,0,1000, 13};
	
	cout << "the array content is: ";
	for (const auto &item : items)
		cout << item << ", ";
	cout << '\n';
	
	for (const auto &value : values)
	{
		const auto idx = binary_search(items, value, sizeof(items)/sizeof(items[0]));

		cout << "searching for " << value << "... ";
		if (idx == -1)
			cout << "NOT FOUND";
		else
			cout << "FOUND on position " << idx;
		cout << '\n';
	}

	cout << endl;
	
	return 0;
}
