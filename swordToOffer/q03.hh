//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q03_HH
#define LEETCODE_Q03_HH

class Solution {
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i)
                ++i;
            else {
                if (nums[nums[i]] == nums[i])
                    return nums[i];
                else {
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return -1;
    }
};

#endif //LEETCODE_Q03_HH
