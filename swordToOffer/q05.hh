//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q05_HH
#define LEETCODE_Q05_HH

class Solution {
public:
    string replaceSpace(string s)
    {
        int cnt = 0, b_size = s.size();
        for (auto ch: s) {
            if (' ' == ch)
                ++cnt;
        }
        int a_size = b_size + 2 * cnt;
        s.resize(a_size);
        --a_size;
        --b_size;
        for (; a_size != b_size; --b_size) {
            if (s[b_size] != ' ') {
                s[a_size--] = s[b_size];
            } else {
                s[a_size--] = '0';
                s[a_size--] = '2';
                s[a_size--] = '%';
            }
        }
        return s;
    }
};

#endif //LEETCODE_Q05_HH
