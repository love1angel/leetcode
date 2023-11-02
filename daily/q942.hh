//
// Created by Helianthus Xie on 2022/5/9.
//

#ifndef LEETCODE_Q942_HH
#define LEETCODE_Q942_HH

class Solution {
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.length(), low = 0, high = n;
        std::vector<int> ret(n + 1);
        for (int i = 0; i < n; ++i) {
            ret[i] = s[i] == 'I' ? low++ : high--;
        }
        ret[n] = high;
        return ret;
    }
};

#endif // LEETCODE_Q942_HH
