//
// Created by Helianthus Xie on 2022/7/19.
//

#ifndef LEETCODE_Q53_2_HH
#define LEETCODE_Q53_2_HH

class Solution {
public:
    int missingNumber(vector<int> &nums)
    {
        int beg = 0, end = nums.size() - 1;
        int mid = beg + (end - beg) / 2;
        while (beg <= end) {
            if (nums[mid] == mid)
                beg = mid + 1;
            else
                end = end - 1;
            mid = beg + (end - beg) / 2;
        }
        return beg;
    }
};

#endif //LEETCODE_Q53_2_HH
