#pragma once

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        recurse(root);
        return ret;
    }

private:
    void recurse(TreeNode* node)
    {
        if (!node)
            return;
        recurse(node->left);
        ret.push_back(node->val);
        recurse(node->right);
    }
    std::vector<int> ret {};
};
