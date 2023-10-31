#pragma once

#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slow = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[slow++] = nums[i];
            }
        }

        return slow;
    }
};
