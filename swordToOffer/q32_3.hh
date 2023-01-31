//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_3_HH
#define LEETCODE_Q32_3_HH

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        std::vector<std::vector<int>> ret;
        std::deque<TreeNode*> queue;
        queue.push_back(root);
        bool flag = true;
        while (!queue.empty()) {
            std::vector<int> each;
            for (int i = 0, cnt = queue.size(); i < cnt; ++i) {
                const auto& first = queue.front();
                each.push_back(first->val);
                if (first->left)
                    queue.push_back(first->left);
                if (first->right)
                    queue.push_back(first->right);
                queue.pop_front();
            }

            if (!flag) {
                for (int i = 0, size = each.size(); i < size / 2; ++i) {
                    std::swap(each[i], each[size - 1 - i]);
                }
            }

            ret.emplace_back(std::move(each));
            flag = !flag;
        }

        return ret;
    }
};

#endif // LEETCODE_Q32_3_HH
