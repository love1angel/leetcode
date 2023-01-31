//
// Created by Helianthus Xie on 2022/7/19.
//

#ifndef LEETCODE_Q53_1_HH
#define LEETCODE_Q53_1_HH

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {
        auto beg = nums.cbegin(), end = nums.cend();
        auto mid = beg + (end - beg) / 2;
        while (mid != end && *mid != target) {
            if (*mid < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }

        if (mid == end) {
            return 0;
        }

        int cnt = 1;
        for (auto i = mid + 1; i < nums.cend(); ++i) {
            if (*i == target) {
                ++cnt;
            }
        }
        for (auto i = mid - 1; i >= nums.cbegin(); --i) {
            if (*i == target) {
                ++cnt;
            }
        }

        return cnt;
    }
};

#endif //LEETCODE_Q53_1_HH
