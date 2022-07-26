//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q35_HH
#define LEETCODE_Q35_HH

class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            auto mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return beg;
    }
};

#endif //LEETCODE_Q35_HH
