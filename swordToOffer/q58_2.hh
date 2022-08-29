//
// Created by Helianthus Xie on 2022/5/10.
//

#ifndef LEETCODE_Q58_HH
#define LEETCODE_Q58_HH

class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        exchange(s, 0, n);
        exchange(s, n, s.size());
        exchange(s, 0, s.size());
        return s;
    }

private:
    void exchange(std::string &s, int beg, size_t end)
    {
        for (int i = 0; i < (end - beg) / 2; ++i) {
            char temp = s[beg + i];
            s[beg + i] = s[end - 1 - i];
            s[end - 1 - i] = temp;
        }
    }
};

#endif //LEETCODE_Q58_HH
