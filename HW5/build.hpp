//
// Created by Servebotfrank on 11/17/2019.
//

#ifndef HW5_BUILD_HPP
#define HW5_BUILD_HPP
#include <vector>
#include <algorithm>

using Bridge = std::vector<int>;

int Recursive(int w, int e, const std::vector<Bridge> & bridges, const std::vector<int> & memory);
int build(int w, int e, const std::vector<Bridge> & bridges);

#endif //HW5_BUILD_HPP
