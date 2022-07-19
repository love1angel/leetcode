//
// Created by Helianthus Xie on 2022/7/19.
//

#ifndef LEETCODE_Q53_1_HH
#define LEETCODE_Q53_1_HH

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size();
        int mid = beg + (end - beg) / 2;
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid;
            mid = beg + (end - beg) / 2;
        }
        int cnt = 0;
        if (mid == end)
            return cnt;
        for (int i = mid; i < nums.size(); ++i) {
            if (nums[i] == target)
                ++cnt;
        }
        for (int i = mid - 1; i >= 0; --i) {
            if (nums[i] == target)
                ++cnt;
        }
        return cnt;
    }
};

#endif //LEETCODE_Q53_1_HH
