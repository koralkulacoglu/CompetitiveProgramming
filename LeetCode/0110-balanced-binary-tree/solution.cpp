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
    bool balanced;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 1;
        int lVal = dfs(node->left);
        int rVal = dfs(node->right);
        if (abs(lVal - rVal) > 1) balanced = false;
        return max(lVal, rVal) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }
};
