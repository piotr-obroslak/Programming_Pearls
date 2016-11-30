#ifndef _MAXIMUM_CONTINUOUS_PARTIAL_SUM_H_
#define _MAXIMUM_CONTINUOUS_PARTIAL_SUM_H_

template<typename data_type>
inline data_type Max(
    const data_type & a,
    const data_type & b)
{
    return (a > b) ? a : b;
}

template<typename data_type>
inline data_type MaxSubarray(
    const data_type *arr,
    const size_t begin,
    const size_t end)
{
    data_type max_till_now = arr[begin];
    data_type max_ending_now = arr[begin];

    for (size_t i=1; i<end; i++) {
        max_ending_now = Max(max_ending_now+arr[i], arr[i]);
        max_till_now = Max(max_till_now, max_ending_now);
    }

    return max_till_now;
}

#endif
