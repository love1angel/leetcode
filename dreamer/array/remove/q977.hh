#pragma once

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret;
        ret.reserve(nums.size());

        int left = 0, right = nums.size() - 1;
        if (nums[left] >= 0) {
            for (const auto& num : nums) {
                ret.push_back(num * num);
            }
        } else if (nums[right] <= 0) {
            for (int i = right; i >= 0; --i) {
                ret.push_back(nums[i] * nums[i]);
            }
        } else {
            int flag = 0;
            while (right - left != 1) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > 0) {
                    right = mid;
                } else if (nums[mid] == 0) {
                    flag = mid;
                    break;
                } else {
                    left = mid;
                }
            }

            if (flag) {
                ret.push_back(0);
                left = flag - 1;
                right = flag + 1;
            }

            while (left >= 0 && right < nums.size()) {
                int left_2 = nums[left] * nums[left], right_2 = nums[right] * nums[right];
                if (left_2 > right_2) {
                    ret.push_back(right_2);
                    ++right;
                } else {
                    ret.push_back(left_2);
                    --left;
                }
            }
            while (left >= 0) {
                ret.push_back(nums[left] * nums[left]);
                --left;
            }
            while (right < nums.size()) {
                ret.push_back(nums[right] * nums[right]);
                ++right;
            }
        }

        return ret;
    }
};
