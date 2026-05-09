class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> endTimes(n+1);
        for (vector<int>& r : rides) endTimes[r[1]].push_back({r[0], r[2]});
        vector<long long> dp(n+1, 0);
        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1];
            for (auto& [start, tip] : endTimes[i]) {
                dp[i] = max(dp[i], i - start + tip + dp[start]);
            }
        }
        return dp[n];
    }
};
