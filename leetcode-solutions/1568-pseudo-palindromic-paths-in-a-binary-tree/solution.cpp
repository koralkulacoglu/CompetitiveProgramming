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

// freq of all elements must be even except for up to 1

class Solution {
public:
    int ans;
    bool isPal(vector<int> freq) {
        bool odd = false;
        for (int i : freq) {
            if (i%2) {
                if (odd) return false;
                odd = true;
            }
        }
        return true;
    }

    void dfs(TreeNode* node, vector<int> freq) {
        freq[node->val]++;
        if (node->left == nullptr && node->right == nullptr) ans += isPal(freq);
        if (node->left) dfs(node->left, freq); 
        if (node->right) dfs(node->right, freq);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        vector<int> freq(10, 0);
        dfs(root, freq);
        return ans;
    }
};
