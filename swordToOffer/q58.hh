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
        exchange(s, n, s.length());
        exchange(s, 0, s.length());
        return s;
    }

private:
    void exchange(std::string &s, int start, int end)
    {
        int end_charge = (end - start) / 2;
        for (int i = 0; i < end_charge; ++i) {
            auto temp = s[end - 1 - i];
            s[end - 1 - i] = s[start + i];
            s[start + i] = temp;
        }
    }
};

#endif //LEETCODE_Q58_HH
