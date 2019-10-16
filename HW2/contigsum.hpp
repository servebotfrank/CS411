//
// Created by Ian Ferguson on 2019-10-16.
//

#ifndef HW2_CONTIGSUM_HPP
#define HW2_CONTIGSUM_HPP

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

}

template<typename RAITER>
int contigSum(RAITER first, RAITER last){
    return 0;
}

#endif //HW2_CONTIGSUM_HPP
