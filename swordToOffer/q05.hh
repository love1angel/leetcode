//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q05_HH
#define LEETCODE_Q05_HH

#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s)
    {
        int cnt = 0;
        for (auto&& ch : s) {
            if (' ' == ch) {
                ++cnt;
            }
        }

        int size = s.size();
        s.resize(size + 2 * cnt);

        for (int i = size - 1; cnt > 0; --i) {
            if (' ' != s[i]) {
                s[i + 2 * cnt] = s[i];
            } else {
                s[i + 2 * cnt] = '0';
                s[i + 2 * cnt - 1] = '2';
                s[i + 2 * cnt - 2] = '%';
                --cnt;
            }
        }
        return s;
    }
};

#endif //LEETCODE_Q05_HH
