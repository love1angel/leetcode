//
// Created by Helianthus Xie on 2022/7/27.
//

#ifndef LEETCODE_Q189_HH
#define LEETCODE_Q189_HH

class Solution {
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

#endif //LEETCODE_Q189_HH
