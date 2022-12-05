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
        size_t cnt = 0;
        for (const auto ch: s) {
            if (ch == ' ')
                ++cnt;
        }

        auto before_size = s.size(), after_idx = before_size + 2 * cnt - 1;
        s.resize(after_idx + 1);
        for (auto i = before_size - 1; cnt > 0; --i) {
            if (s[i] == ' ') {
                --cnt;
                s[after_idx] = '0';
                s[after_idx - 1] = '2';
                s[after_idx - 2] = '%';
                after_idx -= 3;
            } else {
                s[after_idx] = s[i];
                --after_idx;
            }
        }
        return s;
    }
};

#endif //LEETCODE_Q05_HH
