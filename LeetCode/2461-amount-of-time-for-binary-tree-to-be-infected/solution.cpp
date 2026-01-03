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
    map<int, vector<int>> graph;
    void dfs(TreeNode* node) {
        if (node->left != NULL) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            dfs(node->left);
        }
        if (node->right != NULL) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            dfs(node->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        
        queue<pair<int, int>> que;
        map<int, bool> seen;
        
        int ans = 0;
        que.push(make_pair(start, 0));
        seen[start] = true;
        
        while (!que.empty()) {
            pair<int, int> node = que.front();
            
            // cout << node.first << ' ' << node.second << endl;
            que.pop();
            ans = max(ans, node.second);
            for (int neigh : graph[node.first]) {
                if (seen[neigh]) continue;
                
                seen[neigh] = true;
                que.push(make_pair(neigh, node.second+1));
            }
        }
        return ans;
    }
};
