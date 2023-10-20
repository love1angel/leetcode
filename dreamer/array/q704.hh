#pragma once

#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size(), mid = end / 2;
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }

        if (mid == end) {
            return -1;
        } else {
            return mid;
        }
    }
};
