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
        int present = 0x00, flag = 0x00;

        char queue[26];
        int size = 0;

        for (auto ch: s) {
            if (present & 1 << (ch - 'a'))
                flag |= 1 << (ch - 'a');
            else
                queue[size++] = ch;
            present |= 1 << (ch - 'a');
        }

        for (int i = 0; i < size; ++i) {
            if (!(flag & 1 << (queue[i] - 'a'))) {
                return queue[i];
            }
        }
        return ' ';
    }
};

#endif //LEETCODE_Q50_HH
