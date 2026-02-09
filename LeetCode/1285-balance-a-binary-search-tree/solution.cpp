/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> vals;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        vals.push_back(node->val);
        dfs(node->right);
    }

    TreeNode* construct(int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(vals[m]);
        root->left = construct(l, m-1);
        root->right = construct(m+1, r);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vals.clear();
        dfs(root);
        root = construct(0, vals.size()-1);
        return root;
    }
};
