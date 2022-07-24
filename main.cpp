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
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[0] = grid[0][0];
                else if (i == 0) dp[j] = dp[j - 1] + grid[0][j];
                else if (j == 0) dp[0] += grid[i][0];
                else dp[j] = max(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
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

    std::cout << 1e9 << std::endl;
    std::vector<int> s{1, 2, 3};
    auto beg = --s.end();
    std::cout << *beg << std::endl;
    s.push_back(4);
    std::cout << *beg << std::endl;

    return 0;
}
