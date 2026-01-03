class Solution {
public:
    int n;
    vector<vector<int>> paths;
    map<int, vector<int>> mp;

    void dfs(int node, vector<int> path) {
        path.push_back(node);

        if (node == n-1) {
            paths.push_back(path);
            return;
        }

        for (int neigh : mp[node]) dfs(neigh, path);
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        mp.clear();
        paths.clear();

        for (int i=0; i<n; i++) mp[i] = graph[i];
        dfs(0, {});

        return paths;
    }
};
