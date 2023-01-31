//
// Created by Helianthus Xie on 2022/7/24.
//

#ifndef LEETCODE_Q42_HH
#define LEETCODE_Q42_HH

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0, max_sum = nums[0];
        for (const auto& num : nums) {
            pre = std::max(pre + num, num);
            max_sum = std::max(pre, max_sum);
        }
        return max_sum;
    }
};

#endif //LEETCODE_Q42_HH
