//
// Created by Helianthus Xie on 2022/7/22.
//

#ifndef LEETCODE_Q28_HH
#define LEETCODE_Q28_HH

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

#endif //LEETCODE_Q28_HH
