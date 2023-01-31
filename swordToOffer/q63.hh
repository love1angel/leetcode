//
// Created by Helianthus Xie on 2022/7/23.
//

#ifndef LEETCODE_Q63_HH
#define LEETCODE_Q63_HH

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int cur_max = 0, min = INT_MAX;
        for (const auto& price : prices) {
            if (price < min) {
                min = price;
                continue;
            }
            cur_max = price - min > cur_max ? price - min : cur_max;
        }
        return cur_max;
    }
};

#endif // LEETCODE_Q63_HH
