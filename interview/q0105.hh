//
// Created by Helianthus Xie on 2022/5/13.
//

#ifndef LEETCODE_Q0105_HH
#define LEETCODE_Q0105_HH

class Solution {
public:
    bool oneEditAway(string first, string second)
    {
        int f_len = first.length(), s_len = second.length();
        int minus = std::abs(f_len - s_len);
        if (minus > 1) return false;

        if (f_len > s_len) {
            std::swap(first, second);
            std::swap(f_len, s_len);
        }

        int cnt = 0;
        for (int i = 0, j = 0; i < f_len; ++j) {
            if (first[i] != second[j]) {
                if (++cnt > 1)
                    return false;
                if (minus == 0)
                    ++i;
                continue;
            }
            ++i;
        }

        return true;
    }
};

#endif //LEETCODE_Q0105_HH
