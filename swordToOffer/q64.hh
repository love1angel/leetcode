//
// Created by Helianthus Xie on 2022/8/3.
//

#ifndef LEETCODE_Q64_HH
#define LEETCODE_Q64_HH

class Solution {
public:
    int sumNums(int n)
    {
        bool x = n > 1 && (n += sumNums(n - 1)) > 0;
        return n;
    }
};

#endif //LEETCODE_Q64_HH
