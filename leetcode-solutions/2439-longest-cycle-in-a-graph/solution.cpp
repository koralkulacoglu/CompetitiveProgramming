class Solution {
public:
    int ans;
    vector<int> mp;
    vector<int> vis;
    vector<bool> seen, seen2;
    
    void dfs(int node, int depth) {
        if (seen[node]) return;
        if (vis[node]) {
            ans = max(ans, depth - vis[node]);
        }
        else {
            vis[node] = depth;
            seen2[node] = true;
            
            if (mp[node] == -1) return;
            dfs(mp[node], depth+1);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        ans = -1;
        vis.resize(n, 0);
        seen.resize(n, false);
        seen2.resize(n, false);
        mp = edges;
        for (int i=0; i<n; i++) {
            if (seen[i]) continue;
            seen = seen2;
            dfs(i, 1);
        }
        return ans;
    }
};
