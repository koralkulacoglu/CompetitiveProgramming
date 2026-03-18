class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> tree;
        for (int i=0; i<n; i++) tree[parent[i]].push_back(i);

        int ans = 1;

        auto dfs = [&](auto&& self, int node) -> pair<char, int> {
            vector<pair<char, int>> paths;
            for (int neigh : tree[node]) paths.push_back(self(self, neigh));

            int maxLen = 1;
            for (auto path : paths) {
                char prev = path.first;
                int len = path.second;
                if (prev == s[node]) continue;

                ans = max(ans, maxLen + len);
                maxLen = max(maxLen, len + 1);
            }

            return {s[node], maxLen};
        };

        dfs(dfs, 0);

        return ans;
    }
};
