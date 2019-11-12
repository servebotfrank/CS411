//
// Created by Ian Ferguson on 2019-10-16.
//

#ifndef HW2_CONTIGSUM_HPP
#define HW2_CONTIGSUM_HPP
#include <iostream>
#include <limits.h>
#include <algorithm>



//Repurposed to actually follow specifications this time.
//A. The GCS of the sequence.
//B. The greatest possible sum of a contiguous subsequence
//    that includes the first value in the sequence, or zero if all
//    such sums are negative.
//C. The greatest possible sum of a contiguous subsequence
//    that includes the last value in the sequence, or zero if all
//    such sums are negative.
//D. The sum of the entire sequence.


struct GCS
{
    GCS()= default;
    GCS(int gcs, int gcsL, int gcsR, int Sum): gcs(gcs), gcsLeft(gcsL), gcsRight(gcsR), sum(Sum){}
    int gcs=0;
    int gcsLeft = 0;
    int gcsRight=0;
    int sum = 0;
};

//template <typename T>
//T max (T a, T b, T c)
//{
//    return std::max(std::max(a, b), c);
//}

template<typename RAITER>
GCS Recursive(RAITER first, RAITER last, size_t size)
{
    if (size == 1)
    {
        return GCS(*first, *first, *first, *first);

    }
    auto middle = std::next(first, size/2);
    auto left = Recursive(first, middle, std::distance(first, middle));
    auto right = Recursive(middle, last, std::distance(middle, last));

    return GCS(std::max({left.gcsRight+right.gcsLeft, left.gcs, right.gcs}),
            std::max({left.gcs, left.sum + right.gcs}),
            std::max({left.gcs + right.sum, right.gcs}),
            left.sum+right.sum);

}

template<typename RAITER>
int contigSum(RAITER first, RAITER last)
{
    //Previous version, moved and modified to the recursive function
//    RAITER mid =first +  (last-first)/2;
    std::size_t size = std::distance(first, last);

    if(size < 1)
    {
        return 0;
    }
    else
    {
        return std::max(Recursive(first, last, size).gcs, 0);
    }
}

#endif //HW2_CONTIGSUM_HPP
