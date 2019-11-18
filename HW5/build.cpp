//
// Created by Servebotfrank on 11/17/2019.
//

#include "build.hpp"
using std::vector;
using std::sort;

//comparison function
//Code basis taken from https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
bool compare(const Bridge &w, const Bridge &e)
{
    if ( w[0] == e[0])
    {
        return w[1] < e [1];
    }
    else
    {
        return w[0] < e[0];
    }
}


Placer::Placer(int w, int e, const std::vector<Bridge> &bridges): _memory(w+1, vector<int>(e+1, -1))
{

    vector<Bridge> Bridgesort (bridges);
    std::sort(Bridgesort.begin(), Bridgesort.end(), compare);
    returnToll = Recursive(w,e,Bridgesort,_memory);

}

int Placer::Recursive (int w, int e, const std::vector<Bridge> & bridges, std::vector<std::vector<int>> & memory)
{
    int toll = 0;
    if (memory[w][e] != -1)
    {
        return memory[w][e];
    }


    for(auto & b: bridges)
    {
        if (b[0] < w && b[1] < e)
        {
            toll = std::max(Recursive(b[0], b[1], bridges, memory)+b[2], toll);
        }
    }
    memory[w][e] = toll;
    return toll;
}
int Placer::getreturnToll()
{
    return returnToll;
}




//int Recursive(int w, int e, const std::vector<Bridge> & bridges,  vector<vector<int>> & memory)
//{
//    int toll = 0;
//    if ( memory[w][e] != -1)
//    {
//        return memory[w][e];
//    }
//
//
//    for(auto & b: bridges)
//    {
//        if (b[0] < w && b[1] < e)
//        {
//            toll = std::max(Recursive(b[0], b[1], bridges, memory)+b[2], toll);
//        }
//    }
//    memory[w][e] = toll;
//    return toll;
//}

int build(int w, int e, const std::vector<Bridge> & bridges)
{
    if (bridges.size() == 0)
    {
        return 0;
    }
    //Cannot sort with const due to how the swap comparison works
    Placer Placer(w, e, bridges);
    return Placer.getreturnToll();



}
