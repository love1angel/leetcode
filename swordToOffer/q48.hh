//
// Created by Helianthus Xie on 2022/7/25.
//

#ifndef LEETCODE_Q48_HH
#define LEETCODE_Q48_HH

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // dp[0]: current beg
        // dp[1]: current length
        // dp[2]: max length
        int dp[3] = { 0, 0, 0 };
        for (int i = 0; i < s.size(); ++i) {
            if (!m_map.contains(s[i])) {
                ++dp[1];
                m_map[s[i]] = i;
            } else {
                for (int j = dp[0]; j < m_map[s[i]]; ++j) {
                    m_map.erase(s[j]);
                }
                dp[2] = std::max(dp[2], dp[1]);
                dp[0] = m_map[s[i]] + 1;
                dp[1] = i - dp[0] + 1;
                m_map[s[i]] = i;
            }
        }
        dp[2] = std::max(dp[1], dp[2]);
        return dp[2];
    }

private:
    std::unordered_map<char, int> m_map;
};

#endif // LEETCODE_Q48_HH
