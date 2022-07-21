//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_3_HH
#define LEETCODE_Q32_3_HH

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root) return {};
        std::vector<std::vector<int>> ret;
        m_deque.push_back(root);
        bool flag = true;
        while (!m_deque.empty()) {
            std::vector<int> each;
            int size = m_deque.size();
            for (int i = 0; i < size; ++i) {
                const auto &node = m_deque[0];
                each.push_back(node->val);
                if (node->left) m_deque.push_back(node->left);
                if (node->right) m_deque.push_back(node->right);
                m_deque.pop_front();
            }
            if (!flag) {
                for (int i = 0; i < size / 2; ++i) {
                    std::swap(each[i], each[size - 1 - i]);
                }
            }
            ret.push_back(each);
            flag = !flag;
        }
        return ret;
    }

private:
    std::deque<TreeNode *> m_deque;
};

#endif //LEETCODE_Q32_3_HH
