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
    int mostFreq;
    unordered_map<int, int> freq;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        int sum = root->val + leftSum + rightSum;

        freq[sum]++;
        mostFreq = max(mostFreq, freq[sum]);

        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mostFreq = 0;
        dfs(root);

        vector<int> res;
        for (auto i : freq) {
            if (i.second == mostFreq) res.push_back(i.first);
        }

        return res;
    }
};

