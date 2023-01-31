//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q58_2_HH
#define LEETCODE_Q58_2_HH

#include <string>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n)
    {
        exchange(s, 0, n);
        exchange(s, n, s.size());
        exchange(s, 0, s.size());
        return s;
    }

private:
    void exchange(std::string& s, int beg, int end)
    {
        for (int i = 0; i < (end - beg) / 2; ++i) {
            std::swap(s[beg + i], s[end - 1 - i]);
        }
    }
};

#endif // LEETCODE_Q58_2_HH
