//
// Created by Helianthus Xie on 2022/7/25.
//

#ifndef LEETCODE_Q46_HH
#define LEETCODE_Q46_HH

class Solution {
public:
    int translateNum(int num)
    {
        int dp[3] = {0, 1, 1};
        std::string s = std::to_string(num);
        for (int i = 1; i < s.size(); ++i) {
            dp[0] = dp[1];
            dp[1] = dp[2];

            if ((s[i - 1] == '1')
                || (s[i - 1] == '2' && s[i] < '6')) {
                dp[2] += dp[0];
            }
        }
        return dp[2];
    }
};

#endif //LEETCODE_Q46_HH
