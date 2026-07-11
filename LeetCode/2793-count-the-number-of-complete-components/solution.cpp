class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // {#nodes visited, last node's degree}
        function<tuple<int, int, int>(int)> dfs = [&](int node) -> tuple<int, int, int> {
            vis[node] = true;

            bool curValid = true;
            int nodeCount = 0;
            int curDegree = graph[node].size();
            for (int neigh : graph[node]) {
                if (vis[neigh]) continue;

                auto [valid, degree, total] = dfs(neigh);

                curValid &= valid;
                curValid &= (degree == curDegree);
                nodeCount += total;
            }

            // cout << node << ' ' << int(curValid) << ' ' << curDegree << ' ' << (nodeCount + 1) << endl;

            return {curValid, curDegree, nodeCount + 1};
        };

        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            auto [valid, degree, total] = dfs(i);

            // cout << i << ' ' << int(valid) << ' ' << degree << ' ' << total << endl;

            ans += (valid && degree + 1 == total);
        }

        return ans;
    }
};
