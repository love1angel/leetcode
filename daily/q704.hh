//
// Created by Helianthus Xie on 2022/5/11.
//

#ifndef LEETCODE_Q704_HH
#define LEETCODE_Q704_HH

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        auto start = 0UL, end = nums.size();
        auto mid = start + (end - start) / 2;
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        if (mid == end)
            return -1;
        return mid;
    }
};

#endif //LEETCODE_Q704_HH
