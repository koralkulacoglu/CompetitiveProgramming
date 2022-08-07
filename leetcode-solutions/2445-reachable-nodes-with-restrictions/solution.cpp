class Solution {
public:
    map<int, bool> vis;
    map<int, bool> res;
    map<int, vector<int>> graph;
    int ans;
    void dfs(int node) {
        if (res[node]) return;
        if (vis[node]) return;
        vis[node] = true;
        ans++;
        for (int i : graph[node]) {
            dfs(i);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 0;
        res.clear();
        graph.clear();
        vis.clear();
        
        for (int i : restricted) res[i] = true;
        for (auto i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0);
        return ans;
    }
};
