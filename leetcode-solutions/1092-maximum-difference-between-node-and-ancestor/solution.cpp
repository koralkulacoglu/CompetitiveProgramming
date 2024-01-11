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
public:
    int cancer(TreeNode* node, int mxVal, int mnVal) {
        int score = max(abs(mxVal - node->val), abs(mnVal - node->val));
        mxVal = max(mxVal, node->val);
        mnVal = min(mnVal, node->val);
        if (node->left != nullptr) score = max(score, cancer(node->left, mxVal, mnVal));
        if (node->right != nullptr) score = max(score, cancer(node->right, mxVal, mnVal));
        return score;
    }


    int maxAncestorDiff(TreeNode* root) {
        int mnVal = root->val;
        int mxVal = root->val;
        int score = 0;
        if (root->left != nullptr) score = max(score, cancer(root->left, mxVal, mnVal));
        if (root->right != nullptr) score = max(score, cancer(root->right, mxVal, mnVal));
        return score;
    }
};
