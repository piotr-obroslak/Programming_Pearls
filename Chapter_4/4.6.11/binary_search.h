#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

template<
	typename data_type,
	typename comparator_type = std::less<data_type> >
inline int binary_search(
	const data_type *array,
	const data_type &value,
	const int n)
{
	const auto n_less_1 = n-1;
	
	if (n_less_1 < 0)
		return -1;
	
	const auto n_half = n/2;
	const auto &value_mid = array[n_half];

	if (value < value_mid)
		return binary_search(array, value, n_half);
	else if (value > value_mid)
		return binary_search(array + n_half+1, value, n-n_half);
	
	return n_half;
}

#endif
