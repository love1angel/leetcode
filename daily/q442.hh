//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q442_HH
#define LEETCODE_Q442_HH

/**
 * 原地哈希
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ans;
        for (int x : nums) {
            int t = abs(x) - 1;
            if (nums[t] < 0)
                ans.push_back(t + 1);
            else
                nums[t] = -nums[t];
        }
        return ans;
    }
};

#if 0
/**
 * 遍历两次
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        std::vector<int> ret;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
            while (nums[i] != nums[nums[i] - 1])
                std::swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; ++i)
            if (i != nums[i] - 1)
                ret.push_back(nums[i]);

        return ret;
    }
};
#endif

#if 0
/**
 * 遍历单次
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        std::vector<int> ret;
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i + 1) {
                ++i;
                continue;
            }

            int &item = nums[nums[i] - 1];

            if (item < 0) {
                item = nums[i];
                nums[i] = -1;
                ++i;
            } else if (item == nums[i]) {
                ret.push_back(item);
                nums[i] = -1;
                ++i;
            } else {
                int temp = item;
                item = nums[i];
                nums[i] = temp;
            }
        }
        return ret;
    }
};
#endif

#endif // LEETCODE_Q442_HH
