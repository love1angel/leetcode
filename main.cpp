#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

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


int main(int argc, char *argv[])
{
    TreeNode n4(7, nullptr, nullptr);
    TreeNode n3(15, nullptr, nullptr);
    TreeNode n2(20, &n3, &n4);
    TreeNode n1(9, nullptr, nullptr);
    TreeNode n0(3, &n1, &n2);

    Solution solution;
//    auto ret = solution.levelOrder(&n0);

    std::vector<int> s{1, 2, 3};
    auto beg = --s.end();
    std::cout << *beg << std::endl;
    s.push_back(4);
    std::cout << *beg << std::endl;

    return 0;
}
