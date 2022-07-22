//
// Created by Helianthus Xie on 2022/7/22.
//

#ifndef LEETCODE_Q27_HH
#define LEETCODE_Q27_HH

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (!root) return nullptr;
        mirrorTree(root->left);
        mirrorTree(root->right);
        std::swap(root->left, root->right);
        return root;
    }
};

#endif //LEETCODE_Q27_HH
