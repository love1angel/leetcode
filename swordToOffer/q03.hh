//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q03_HH
#define LEETCODE_Q03_HH

#include <vector>

class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums)
    {
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i) {
                ++i;
                continue;
            } else {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        return {};
    }
};

#endif //LEETCODE_Q03_HH
