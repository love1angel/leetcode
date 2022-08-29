//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q05_HH
#define LEETCODE_Q05_HH

class Solution {
public:
    string replaceSpace(string s)
    {
        int cnt = 0, before = s.size();
        for (const auto ch: s) {
            if (ch == ' ') {
                ++cnt;
            }
        }

        int after = before + 2 * cnt;
        s.resize(after);

        for (--before, --after; before < after; --before) {
            if (s[before] == ' ') {
                s[after--] = '0';
                s[after--] = '2';
                s[after--] = '%';
            } else {
                s[after--] = s[before];
            }
        }

        return s;
    }
};

#endif //LEETCODE_Q05_HH
