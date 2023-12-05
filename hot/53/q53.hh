#pragma once

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0, max = nums[0];
        for (const auto& num : nums) {
            pre = std::max(num, pre + num);
            max = std::max(max, pre);
        }
        return max;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        return maxSubsequence(nums, 0, nums.size() - 1).mMax;
    }

private:
    struct Status {
        int lMax {}; // 左端点始 最大子段和
        int rMax {}; // 右端点始 最大子段和
        int sum {}; // 区间和
        int mMax {}; // 最大和取（左区间最大和，右区间最大和，横跨中间和）
    };

    Status maxSubsequence(vector<int>& nums, int l, int r)
    {
        if (l == r) {
            return { nums[l], nums[l], nums[l], nums[l] };
        }
        int m = (l + r) >> 1;
        Status left = maxSubsequence(nums, l, m);
        Status right = maxSubsequence(nums, m + 1, r);

        int lMax = std::max(left.lMax, left.sum + right.lMax);
        int rMax = std::max(right.rMax, right.sum + left.rMax);
        int sum = left.sum + right.sum;
        int mMax = std::max(std::max(left.mMax, right.mMax), left.rMax + right.lMax);

        return {
            lMax,
            rMax,
            sum,
            mMax
        };
    }
};
