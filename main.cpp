#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // dp[0]: current beg
        // dp[1]: current length
        // dp[2]: max length
        int dp[3] = {0, 0, 0};
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


int main(int argc, char *argv[])
{

    TreeNode n6(9, nullptr, nullptr);
    TreeNode n5(6, nullptr, nullptr);
    TreeNode n4(3, nullptr, nullptr);
    TreeNode n3(1, nullptr, nullptr);
    TreeNode n2(7, &n5, &n6);
    TreeNode n1(2, &n3, &n4);
    TreeNode n0(4, &n1, &n2);

    Solution solution;

    std::cout << solution.lengthOfLongestSubstring("abba") << std::endl;

    return 0;
}
