//
// Created by Helianthus Xie on 2022/8/2.
//

#ifndef LEETCODE_Q55_2_HH
#define LEETCODE_Q55_2_HH

class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }

private:
    int height(TreeNode *root)
    {
        if (!root) return 0;
        auto left = height(root->left);
        auto right = height(root->right);
        if (left == -1 || right == -1 || std::abs(left - right) > 1)
            return -1;
        return std::max(left, right) + 1;
    }
};

#endif //LEETCODE_Q55_2_HH
