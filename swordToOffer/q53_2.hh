//
// Created by Helianthus Xie on 2022/7/19.
//

#ifndef LEETCODE_Q53_2_HH
#define LEETCODE_Q53_2_HH

#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int> &nums)
    {
        int beg = 0, end = nums.size(), mid = beg + (end - beg) / 2;
        while (mid != end) {
            if (nums[mid] == mid) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }
        return beg;
    }
};

#endif //LEETCODE_Q53_2_HH
