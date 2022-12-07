//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_2_HH
#define LEETCODE_Q32_2_HH

#include <vector>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        if (!root) return {};

        std::vector<std::vector<int>> ret;
        std::deque<TreeNode *> list;
        list.push_back(root);
        while (!list.empty()) {
            auto cnt = list.size();
            std::vector<int> each;
            for (int i = 0; i < cnt; ++i) {
                const auto &first = list.front();
                each.push_back(first->val);
                if (first->left) list.push_back(first->left);
                if (first->right) list.push_back(first->right);
                list.pop_front();
            }
            ret.emplace_back(std::move(each));
        }

        return ret;
    }
};

#endif //LEETCODE_Q32_2_HH
