//
// Created by Helianthus Xie on 2022/7/28.
//

#ifndef LEETCODE_Q57_HH
#define LEETCODE_Q57_HH

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int s = nums[i] + nums[j];
            if (s < target)
                i++;
            else if (s > target)
                j--;
            else
                return { nums[i], nums[j] };
        }
        return {};
    }
};

#endif // LEETCODE_Q57_HH
