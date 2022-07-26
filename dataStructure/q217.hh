//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q217_HH
#define LEETCODE_Q217_HH

class Solution {
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (const auto &num: nums) {
            if (m_set.contains(num))
                return true;
            else
                m_set.insert(num);
        }
        return false;
    }

private:
    std::unordered_set<int> m_set;
};

#endif //LEETCODE_Q217_HH
