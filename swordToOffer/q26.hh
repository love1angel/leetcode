//
// Created by Helianthus Xie on 2022/7/22.
//

#ifndef LEETCODE_Q26_HH
#define LEETCODE_Q26_HH

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        return (A && B) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recur(TreeNode* left, TreeNode* right)
    {
        if (!right)
            return true;
        if (!left || left->val != right->val)
            return false;
        return recur(left->left, right->left)
            && recur(left->right, right->right);
    }
};

#endif // LEETCODE_Q26_HH
