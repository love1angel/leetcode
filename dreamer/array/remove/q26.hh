#pragma once

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int current = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == current) {
                continue;
            } else {
                nums[cnt++] = nums[i];
                current = nums[i];
            }
        }
        return cnt;
    }
};
