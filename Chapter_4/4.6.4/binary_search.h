#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

template<
	typename data_type,
	typename comparator_type = std::less<data_type> >
inline int binary_search(
	const data_type *array,
	const data_type &value,
	const int l, const int u,
	double &call_count)
{
	++call_count;
	
	const auto u1 = u-1;
	
	if (l > u1)
		return -1;
	
	const auto idx_mid = (u1 + l) / 2;
	const auto &value_mid = array[idx_mid];

	if (value < value_mid)
		return binary_search(array, value, l, idx_mid, call_count);
	else if (value > value_mid)
		return binary_search(array, value, idx_mid+1, u, call_count);
	
	return idx_mid;
}

#endif
