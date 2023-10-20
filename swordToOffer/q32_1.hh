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
        if (not root)
            return {};
        std::vector<int> ret;
        std::deque<TreeNode*> queue { root };

        do {
            const auto& head = queue.front();
            ret.push_back(head->val);
            if (head->left)
                queue.push_back(head->left);
            if (head->right)
                queue.push_back(head->right);
            queue.pop_front();
        } while (!queue.empty());

        return ret;
    }
};

#endif // LEETCODE_Q32_1_HH
