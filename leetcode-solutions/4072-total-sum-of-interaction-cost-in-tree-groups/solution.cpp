class Solution {
    vector<vector<int>> adj;
    vector<int> total_group_counts;
    long long total_cost = 0;

    vector<int> dfs(int u, int p, const vector<int>& group) {
        vector<int> subtree_counts(22, 0);
        subtree_counts[group[u]] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            vector<int> child_counts = dfs(v, u, group);
            for (int g = 1; g <= 20; ++g) {
                if (child_counts[g] > 0) {
                    long long in_subtree = child_counts[g];
                    long long out_subtree = total_group_counts[g] - in_subtree;
                    total_cost += in_subtree * out_subtree;
                    subtree_counts[g] += child_counts[g];
                }
            }
        }
        return subtree_counts;
    }

public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.assign(n, vector<int>());
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        total_group_counts.assign(22, 0);
        for (int g : group) {
            total_group_counts[g]++;
        }

        total_cost = 0;
        dfs(0, -1, group);

        return total_cost;
    }
};
