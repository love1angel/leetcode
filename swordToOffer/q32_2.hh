//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_2_HH
#define LEETCODE_Q32_2_HH

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
        std::deque<TreeNode*> queue { root };
        while (!queue.empty()) {
            const auto size = queue.size();
            std::vector<int> each;
            for (decltype(queue.size()) i = 0; i < size; ++i) {
                const auto& head = queue.front();
                each.push_back(head->val);
                if (head->left)
                    queue.push_back(head->left);
                if (head->right)
                    queue.push_back(head->right);
                queue.pop_front();
            }
            ret.emplace_back(std::move(each));
        }
        return ret;
    }
};

#endif // LEETCODE_Q32_2_HH
