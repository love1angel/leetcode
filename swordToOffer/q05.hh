//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q05_HH
#define LEETCODE_Q05_HH

class Solution {
public:
    string replaceSpace(string s)
    {
        int cnt = 0, old = s.length();
        for (const auto ch: s) {
            if (ch == ' ')
                ++cnt;
        }
        int n = old + 2 * cnt;
        s.resize(n);
        for (int i = old - 1; cnt > 0; --i) {
            if (s[i] == ' ') {
                --cnt;
                s[i + 2 * cnt] = '%';
                s[i + 2 * cnt + 1] = '2';
                s[i + 2 * cnt + 2] = '0';
            } else {
                s[i + 2 * cnt] = s[i];
            }
        }
        return s;
    }
};

#endif //LEETCODE_Q05_HH
