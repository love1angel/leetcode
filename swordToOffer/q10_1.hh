//
// Created by Helianthus Xie on 2022/7/23.
//

#ifndef LEETCODE_Q10_1_HH
#define LEETCODE_Q10_1_HH

class Solution {
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        int bef = 0, next = 1;
        for (int i = 1; i < n; ++i) {
            int temp = next;
            next += bef;
            next %= 1000000007;
            bef = temp;
        }
        return next;
    }
};

#endif //LEETCODE_Q10_1_HH
