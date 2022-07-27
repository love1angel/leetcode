//
// Created by Helianthus Xie on 2022/7/27.
//

#ifndef LEETCODE_Q977_HH
#define LEETCODE_Q977_HH

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};

#endif //LEETCODE_Q977_HH
