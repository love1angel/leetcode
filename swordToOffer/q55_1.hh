//
// Created by Helianthus Xie on 2022/8/2.
//

#ifndef LEETCODE_Q55_1_HH
#define LEETCODE_Q55_1_HH

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#endif //LEETCODE_Q55_1_HH
