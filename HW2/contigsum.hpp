//
// Created by Ian Ferguson on 2019-10-16.
//

#ifndef HW2_CONTIGSUM_HPP
#define HW2_CONTIGSUM_HPP
#include <iostream>
#include <limits.h>

int max (int a, int b)
{
    if(a>b)
    {
        return a;
    } else return b;
}

int max (int a, int b, int c)
{
    return max(max(a, b), c);
}

template<typename RAITER>
int Conquer(RAITER first, RAITER mid,  RAITER last)
{
    //Left of mid
    int sum= 0;
    int left_sum = 0;
    for (RAITER i = mid; i>= first; i-- )
    {
        sum= sum + *i;
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    //Right of mid
    sum = 0;
    int right_sum = 0;
    for (RAITER i= mid+1; i<=last; i++)
    {
        sum = sum + *i;
        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }


    //Combine the two
    return left_sum + right_sum;

}

template<typename RAITER>
int contigSum(RAITER first, RAITER last)
{
    RAITER mid =first +  (last-first)/2;
    std::size_t size = std::distance(first, last);
    if(first == last-1)
    {
        if(*first <0)
        {
            return 0;
        }
        else
        {
            return *first;
        }
    }
    if(size < 1)
    {
        return 0;
    }
    else
    {
        return max(contigSum(first, mid), contigSum(mid+1,last), Conquer(first, mid, last-1));
    }
}

#endif //HW2_CONTIGSUM_HPP
