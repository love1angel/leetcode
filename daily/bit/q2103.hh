#pragma once

#include <bitset>
#include <string>

using std::string;

class Solution {
public:
    int countPoints(string rings)
    {
        std::bitset<30> arr {};
        for (int i = 0; i < rings.size(); i += 2) {
            if ('R' == rings[i]) {
                arr |= 1 << (rings[i + 1] - '0') * 3;
            } else if ('G' == rings[i]) {
                arr |= 1 << (rings[i + 1] - '0') * 3 + 1;
            } else {
                arr |= 1 << (rings[i + 1] - '0') * 3 + 2;
            }
        }

        int cnt {};
        std::bitset<30> mask = 0b111;
        for (int i = 0; i < 10; ++i) {
            if ((arr & mask) == mask) {
                ++cnt;
            }
            mask <<= 3;
        }
        return cnt;
    }
};
