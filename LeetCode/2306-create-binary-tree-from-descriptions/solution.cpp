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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = 1e5 + 1;
        vector<TreeNode*> mp(n);
        vector<bool> isRoot(n, true), inTree(n, false);
        for (vector<int>& d : descriptions) {
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];
            TreeNode* p = (mp[parent] ? mp[parent] : new TreeNode(parent));
            TreeNode* c = (mp[child] ? mp[child] : new TreeNode(child));
            if (isLeft) p->left = c;
            else p->right = c;
            mp[parent] = p;
            mp[child] = c;
            isRoot[child] = false;
            inTree[parent] = true;
            inTree[child] = true;
        }
        for (int i=0; i<n; i++) {
            if (inTree[i] && isRoot[i]) return mp[i];
        }
        return nullptr;
    }
};
