#pragma once

#include <bitset>

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        std::bitset<32> mask = 0b1;
        for (int i = 0; i < 31; ++i) {
            if (mask == n) {
                return true;
            }
            mask <<= 1;
        }
        return false;
    }
};
