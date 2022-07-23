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
    int maxProfit(vector<int> &prices)
    {
        int cur_max = 0, min = INT_MAX;
        for (const auto &price: prices) {
            min = price > min ? min : price;
            cur_max = price - min > cur_max ? price - min : cur_max;
        }
        return cur_max;
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
