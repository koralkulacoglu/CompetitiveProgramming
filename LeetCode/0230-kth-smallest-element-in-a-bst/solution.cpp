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
    multiset<int> vals;
public:
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        vals.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        for (int val : vals) {
            k--;
            if (k == 0) return val;
        }
        return -1;
    }
};
