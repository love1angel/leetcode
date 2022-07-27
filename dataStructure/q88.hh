//
// Created by Helianthus Xie on 2022/7/27.
//

#ifndef LEETCODE_Q88_HH
#define LEETCODE_Q88_HH

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int tail = m + n - 1;
        int p1 = m - 1, p2 = n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

#endif //LEETCODE_Q88_HH
