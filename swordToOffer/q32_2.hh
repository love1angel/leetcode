//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_2_HH
#define LEETCODE_Q32_2_HH

class Solution {
public:
    vector <vector<int>> levelOrder(TreeNode *root)
    {
        if (!root) return {};
        std::vector <std::vector<int>> ret;
        m_deque.push_back(root);
        while (!m_deque.empty()) {
            std::vector<int> each;
            for (int size = m_deque.size(); size > 0; --size) {
                each.push_back(m_deque[0]->val);
                if (m_deque[0]->left) m_deque.push_back(m_deque[0]->left);
                if (m_deque[0]->right) m_deque.push_back(m_deque[0]->right);
                m_deque.pop_front();
            }
            ret.push_back(each);
        }
        return ret;
    }

private:
    std::deque<TreeNode *> m_deque;
};

#endif //LEETCODE_Q32_2_HH
