/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* node) {
        vector<vector<int>> a(n, vector<int>(m, -1));
        
        map<pair<int, int>, bool> vis;
        for (int i=-1; i<=n; i++) {
           vis[{i, m}] = true;
           vis[{i, -1}] = true;
        }
        for (int j=-1; j<=m; j++) {
            vis[{n, j}] = true;
            vis[{-1, j}] = true;
        }
        
        vis[{0, 0}] = true;
        a[0][0] = node->val;
        
        if (node->next == NULL) {
            return a;
        }
        node = node->next;

        int i=(m<=1), j=(m>1);
        while (true) {
            int cur = node->val;
            a[i][j] = cur;
            
            vis[{i, j}] = true;
            // cout << i << ' ' << j << '\n';
            if (vis[{i, j+1}] && vis[{i-1, j}] && !vis[{i+1, j}]) {
                i++;
            }
            else if (vis[{i, j-1}] && vis[{i+1, j}] && !vis[{i-1, j}]) {
                i--;
            }
            else if (vis[{i, j+1}] && vis[{i+1, j}] && !vis[{i, j-1}]) {
                j--;
            }
            else if (vis[{i-1, j}] && vis[{i, j-1}] && !vis[{i, j+1}]) {
                j++;
            }
            
            
            if (node->next == NULL) break;
            node = node->next;
        }
        return a;
    }
};
