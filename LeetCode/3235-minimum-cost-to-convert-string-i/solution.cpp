class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        vector<vector<long long>> costs(26, vector<long long>(26, 1e18));
        for (int i=0; i<26; i++) costs[i][i] = 0;
        for (int i=0; i<m; i++) {
            char u = original[i] - 'a';
            char v = changed[i] - 'a';
            long long c = cost[i];
            costs[u][v] = min(costs[u][v], c);
        }

       	for (int k=0; k<26; k++) {
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i=0; i<n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            ans += costs[u][v];
            if (ans >= 1e18) return -1;
        }

        return ans;
    }
};
