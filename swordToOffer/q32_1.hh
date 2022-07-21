//
// Created by Helianthus Xie on 2022/7/21.
//

#ifndef LEETCODE_Q32_1_HH
#define LEETCODE_Q32_1_HH

class Solution {
public:
    vector<int> levelOrder(TreeNode *root)
    {
        std::vector<int> ret;
        m_deque.push_back(root);
        while (!m_deque.empty() && (root = m_deque.front())) {
            ret.push_back(root->val);
            if (root->left)
                m_deque.push_back(root->left);
            if (root->right)
                m_deque.push_back(root->right);
            m_deque.pop_front();
        }
        return ret;
    }

private:
    std::deque<TreeNode *> m_deque;
};

#endif //LEETCODE_Q32_1_HH
