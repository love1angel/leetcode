//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q03_HH
#define LEETCODE_Q03_HH

// similar question q442

class Solution {
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i) {
                ++i;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];

            std::swap(nums[i], nums[nums[i]]);
        }
        return 0;
    }
};

#endif //LEETCODE_Q03_HH
