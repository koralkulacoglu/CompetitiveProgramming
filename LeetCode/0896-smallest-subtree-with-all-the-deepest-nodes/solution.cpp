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
    pair<TreeNode*, int> dfs(TreeNode* node, int depth=0) {
        if (node == nullptr) return {node, depth};

        auto left = dfs(node->left, depth+1);
        auto right = dfs(node->right, depth+1);

        if (left.second == right.second) return {node, left.second};
        if (left.second > right.second) return left;

        return right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
