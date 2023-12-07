#pragma once

#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int beg = 0, end = nums.size(), mid = beg + (end - beg) / 2;
        while (mid != end && nums[mid] != target) {
            if (nums[mid] > target) {
                end = mid;
            } else {
                beg = mid + 1;
            }
            mid = beg + (end - beg) / 2;
        }

        if (mid == end) {
            return -1;
        }
        return mid;
    }

    int search2(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int search3(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
