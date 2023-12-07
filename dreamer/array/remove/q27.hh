#pragma once

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slow = 0;
        while (slow < nums.size() && nums[slow] != val) {
            ++slow;
        }
        int fast = slow + 1;
        while (fast < nums.size()) {
            if (nums[fast] == val) {
                ++fast;
                continue;
            }
            nums[slow++] = nums[fast++];
        }
        return slow;
    }
};
