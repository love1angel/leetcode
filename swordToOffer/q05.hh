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
        auto space_num = 0;
        for (auto&& ch : s) {
            if (ch == ' ') {
                ++space_num;
            }
        }
        int before = s.size(), after = before + 2 * space_num;
        s.resize(after);

        for (; space_num;) {
            --before, --after;
            if (s[before] == ' ') {
                s[after] = '0';
                s[after - 1] = '2';
                s[after - 2] = '%';
                after -= 2;
                --space_num;
            } else {
                s[after] = s[before];
            }
        }
        return s;
    }
};

#endif // LEETCODE_Q05_HH
