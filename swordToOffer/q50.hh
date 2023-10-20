//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q50_HH
#define LEETCODE_Q50_HH

#include <string>

class Solution {
public:
    char firstUniqChar(std::string s)
    {
        std::uint32_t flag = 0x00, dul = 0x00;
        char queue[26];
        int size = 0;
        for (auto&& ch : s) {
            if (!(flag & 1 << ch - 'a')) [[unlikely]] {
                queue[size++] = ch;
                flag |= 1 << ch - 'a';
            } else [[likely]] {
                dul |= 1 << ch - 'a';
            }
        }
        for (int i = 0; i < size; ++i) {
            if (!(dul & 1 << queue[i] - 'a')) {
                return queue[i];
            }
        }
        return ' ';
    }
};

#endif // LEETCODE_Q50_HH
