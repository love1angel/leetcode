#pragma once

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0, max = std::numeric_limits<int>::min();
        for (int num : nums) {
            pre = std::max(num, pre + num);
            max = std::max(pre, max);
        }
        return max;
    }
};

class Solution {
    struct Status {
        int m_left {}; // 左端点始 最大子段和
        int m_right {}; // 右端点始 最大子段和
        int m_sum {}; // 区间和
        int m_max {}; // 最大和 取（左区间最大和，右区间最大和，横跨中间和）
    };

public:
    int maxSubArray(vector<int>& nums)
    {
        return recurse(nums, 0, nums.size() - 1).m_max;
    }

private:
    Status recurse(std::vector<int>& nums, int left, int right)
    {
        if (left == right)
            return { nums[left], nums[left], nums[left], nums[left] };

        int mid = left + (right - left) / 2;
        Status l = recurse(nums, left, mid);
        Status r = recurse(nums, mid + 1, right);

        return {
            std::max(l.m_left, l.m_sum + r.m_left),
            std::max(r.m_right, r.m_sum + l.m_right),
            l.m_sum + r.m_sum,
            std::max(std::max(l.m_max, r.m_max), l.m_right + r.m_left)
        };
    }
};
