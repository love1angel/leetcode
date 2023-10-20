//
// Created by Helianthus Xie on 2022/7/23.
//

#ifndef LEETCODE_Q10_2_HH
#define LEETCODE_Q10_2_HH

#include <tuple>

class Solution {
public:
    int numWays(int n)
    {
        int n_1 = 0, n_2 = 1;
        for (int i = 0; i < n; ++i) {
            std::tie(n_1, n_2) = std::make_tuple(n_2 % 1000000007, (n_1 + n_2) % 1000000007);
        }
        return n_2;
    }
};

#endif // LEETCODE_Q10_2_HH
