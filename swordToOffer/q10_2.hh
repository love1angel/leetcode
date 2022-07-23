//
// Created by Helianthus Xie on 2022/7/23.
//

#ifndef LEETCODE_Q10_2_HH
#define LEETCODE_Q10_2_HH

class Solution {
public:
    int numWays(int n)
    {
        if (n < 1)
            return 1;
        int n_2 = 1, n_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = n_1;
            n_1 += n_2;
            n_1 %= 1000000007;
            n_2 = temp;
        }
        return n_1;
    }
};

#endif //LEETCODE_Q10_2_HH
