//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_1_HH
#define LEETCODE_Q32_1_HH

#include <deque>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    std::vector<int> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        std::vector<int> ret;
        std::deque<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            const auto& first = queue.front();
            ret.push_back(first->val);
            if (first->left)
                queue.push_back(first->left);
            if (first->right)
                queue.push_back(first->right);
            queue.pop_front();
        }

        return ret;
    }
};

#endif // LEETCODE_Q32_1_HH
