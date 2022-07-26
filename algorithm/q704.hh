//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q704_HH
#define LEETCODE_Q704_HH

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size();
        auto mid = beg + (end - beg) / 2;
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }

        if (mid == end)
            return -1;
        return mid;
    }
};

#endif //LEETCODE_Q704_HH
