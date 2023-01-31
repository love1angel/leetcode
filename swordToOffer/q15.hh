#ifndef LEETCODE_Q15_HH
#define LEETCODE_Q15_HH

#include <cstdint>
class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        int bit = 0;
        while (bit <= 32 && n) {
            if (1 << bit & n) {
                ret += 1;
                n &= ~(1 << bit);
            }
            ++bit;
        }
        return ret;
    }
};

#endif // LEETCODE_Q15_HH