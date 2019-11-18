//
// Created by Servebotfrank on 11/17/2019.
//

#ifndef HW5_BUILD_HPP
#define HW5_BUILD_HPP
#include <vector>
#include <algorithm>

using Bridge = std::vector<int>;

class Placer
{
public:
    Placer(int w, int e, const std::vector<Bridge> & bridges);
    int getreturnToll();

private:
    int Recursive (int w, int e, const std::vector<Bridge> & bridges, std::vector<std::vector<int>> &memory);
    //Vector of vector that will keep track of previous answers
    //Top down Dynamic Programming
    std::vector<std::vector<int>> _memory;

    int returnToll;

};

bool compare(const Bridge &w, const Bridge &e);
int build(int w, int e, const std::vector<Bridge> & bridges);

#endif //HW5_BUILD_HPP
