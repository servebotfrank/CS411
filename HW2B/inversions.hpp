// merge_sort.cpp
// Ian Ferguson, Code taken from Glenn G. Chappell
// 16 Oct 2019
//
// For CS 411/611 Fall 2015
// Merge Sort using Iterators

#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <type_traits>

#ifndef HW2B_inversions_HPP
#define HW2B_inversions_HPP


// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now sorted by < (in a stable manner).
template <typename FDIter>
size_t stableMerge(FDIter first, FDIter middle, FDIter last)
{
    using Value = typename std::iterator_traits<FDIter>::value_type;
    size_t inversions = 0;


    std::vector<Value> buffer(distance(first, last));
    // Buffer for temporary copy of data
    FDIter in1 = first;         // Read location in 1st half
    FDIter in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer
    // ** auto! That *is* better than vector<Value>::iterator

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)// Must do comparison this way, to be stable.
        {
            *out++ = *in2++;
            inversions += distance(in1, middle);
        }

        else
            *out++ = *in1++;
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    copy(in1, middle, out);
    copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    copy(buffer.begin(), buffer.end(), first);
    return inversions;
}


// mergeSort
// Sorts a sequence, using Merge Sort.
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename FDIter>
size_t mergeSort(FDIter first, FDIter last)
{
    // Compute size of sequence
    size_t size = distance(first, last);
    size_t inversions = 0;

    // BASE CASE
    if (size <= 1)
        return 0;

    // RECURSIVE CASE
    FDIter middle = std::next(first, size/2);

    // Recursively sort the two lists
    inversions += mergeSort(first, middle);
    inversions +=mergeSort(middle, last);

    // And merge them
    inversions +=stableMerge(first, middle, last);
    return inversions;
}

template<typename RAIter>
size_t inversions(RAIter first, RAIter last)
{
    if (std::distance(first, last)< 1)
    {
        return 0;
    }
    else
    {
        return mergeSort(first, last);
    }
}

#endif //HW2B_inversions_HPP

