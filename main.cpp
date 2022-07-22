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
    bool isSymmetric(TreeNode *root)
    {
        return recur(root, root);
    }

    bool recur(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) return true;
        return (left && right) && left->val == right->val &&
               recur(left->left, right->right) &&
               recur(left->right, right->left);
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

    auto ret = solution.mirrorTree(&n0);
    std::vector<int> s{1, 2, 3};
    auto beg = --s.end();
    std::cout << *beg << std::endl;
    s.push_back(4);
    std::cout << *beg << std::endl;

    return 0;
}
