#pragma once

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
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
        recurse(node->right);
        ret.push_back(node->val);
    }
    std::vector<int> ret {};
};
