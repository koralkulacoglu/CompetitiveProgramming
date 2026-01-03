class Solution {
    int MOD = 1e9+7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=target; j++) {
                for (int l=1; l<=k; l++) {
                    if (l > j) break;
                    dp[i][j] += dp[i-1][j-l];
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[n][target];
    }
};
