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

    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        auto [sumL, sizeL] = dfs(node->left);
        auto [sumR, sizeR] = dfs(node->right);
        int sum = sumL + sumR + node->val;
        int size = sizeL + sizeR + 1;
        if (sum / size == node->val) ans++;
        return {sum, size};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
