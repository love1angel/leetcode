//
// Created by Helianthus Xie on 2022/5/13.
//

#ifndef LEETCODE_Q1_HH
#define LEETCODE_Q1_HH

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> m_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (m_map.count(target - nums[i]))
                return {i, m_map[target - nums[i]]};
            m_map[nums[i]] = i;
        }
        return {};
    }
};

#endif //LEETCODE_Q1_HH
