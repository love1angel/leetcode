#pragma once

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        recurse(root);
        return ret;
    }

private:
    void recurse(TreeNode* node)
    {
        if (!node)
            return;
        ret.push_back(node->val);
        recurse(node->left);
        recurse(node->right);
    }
    std::vector<int> ret;
};
