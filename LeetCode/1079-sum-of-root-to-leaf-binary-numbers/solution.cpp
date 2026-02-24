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
    int ans;

    void dfs(TreeNode* node, int val=0) {
        val <<= 1;
        val += node->val;
        if (node->left) dfs(node->left, val);
        if (node->right) dfs(node->right, val);
        if (!node->left && !node->right) ans += val;
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
