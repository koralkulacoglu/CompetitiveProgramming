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
class BSTIterator {
    vector<int> nums;

    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) return {};

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        vector<int> cur;
        for (int i : left) cur.push_back(i);
        cur.push_back(node->val);
        for (int i : right) cur.push_back(i);

        return cur;
    }

    int n;
    int idx;

public:
    BSTIterator(TreeNode* root) {
        nums = dfs(root);
        n = nums.size();
        idx = 0;
    }
    
    int next() {
        return nums[idx++];
    }
    
    bool hasNext() {
        return idx < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
