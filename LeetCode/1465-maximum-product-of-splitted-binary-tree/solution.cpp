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
    int MOD = 1e9 + 7;
    vector<long long> sums;

    long long dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        long long leftSum = dfs(node->left);
        long long rightSum = dfs(node->right);
        long long nodeSum = node->val + leftSum + rightSum;
        sums.push_back(nodeSum);
        return nodeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        dfs(root);
        int n = sums.size();
        long long totalSum = sums[n-1];
        long long ans = -1e9;
        for (int i : sums) {
            long long leftSum = i;
            long long rightSum = totalSum - i;
            ans = max(ans, leftSum * rightSum);
        }

        return ans % MOD;
    }
};

