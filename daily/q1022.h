//
// Created by Helianthus Xie on 2022/5/31.
//

#ifndef LEETCODE_Q1022_H
#define LEETCODE_Q1022_H

class Solution {
public:
    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root, 0);
        return m_ans;
    }

    int dfs(TreeNode *node, int cur)
    {
        int n_cur = (cur << 1) + node->val;
        if (node->left) dfs(node->left, n_cur);
        if (node->right) dfs(node->right, n_cur);
        if (!node->left && !node->right) m_ans += n_cur;
    }

private:
    int m_ans = 0;
};

#endif //LEETCODE_Q1022_H
