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
    bool dfs(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;

        if (!dfs(node->left, minVal, node->val)) return false;
        if (!dfs(node->right, node->val, maxVal)) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1e18, 1e18);
    }
};
