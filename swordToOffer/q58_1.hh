//
// Created by Helianthus Xie on 2022/7/28.
//

#ifndef LEETCODE_Q58_1_HH
#define LEETCODE_Q58_1_HH

class Solution {
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int right = i;
                while (i >= 0 && s[i] != ' ') {
                    i--;
                }
                ans += s.substr(i + 1, right - i) + " ";
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};

#endif // LEETCODE_Q58_1_HH
