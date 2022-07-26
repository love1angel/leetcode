//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q53_HH
#define LEETCODE_Q53_HH

class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, max_sum = nums[0];
        for (const auto &num: nums) {
            pre = std::max(pre + num, num);
            max_sum = std::max(max_sum, pre);
        }
        return max_sum;
    }
};

#endif //LEETCODE_Q53_HH
