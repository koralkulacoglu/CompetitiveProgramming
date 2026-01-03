class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        // for (int i=0; i<n; i++) edges[i]--;
        
        vector<int> vis(n, 1e9);
        queue<pair<int, int>> que;
        
        que.push(make_pair(node1, 0));
        vis[node1] = 0;
        
        while (!que.empty()) {
            pair<int, int> node = que.front();
            que.pop();
            
            int nNode = edges[node.first];
            if (nNode == -1) continue;
            
            int dist = node.second + 1;
            if (dist < vis[nNode]) {
                que.push(make_pair(nNode, dist));
                vis[nNode] = dist;
            }
        }
        
        vector<int> vis2(n, 1e9);
        queue<pair<int, int>> que2;
        
        que2.push(make_pair(node2, 0));
        vis2[node2] = 0;
        
        while (!que2.empty()) {
            pair<int, int> node = que2.front();
            que2.pop();
            
            int nNode = edges[node.first];
            if (nNode == -1) continue;
            
            int dist = node.second + 1;
            if (dist < vis2[nNode]) {
                que2.push(make_pair(nNode, dist));
                vis2[nNode] = dist;
            }
        }
        int res = -1;
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            int val = max(vis[i], vis2[i]);
            if (val < ans) {
                ans = val;
                res = i;
            }
            // cout << vis[i] << ' ' << vis2[i] << '\n';
        }
        
        return res;
    }
};
