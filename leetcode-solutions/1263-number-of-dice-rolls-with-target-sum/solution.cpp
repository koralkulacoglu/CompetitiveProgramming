class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        long long MOD = 1e9+7;
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));

        dp[0][0] = 1;
        for (int i=1; i<=min(k, target); i++) dp[1][i] = 1;
        
        for (int i=2; i<=n; i++) {
            for (int j=i; j<=target; j++) {
                for (int l=1; l<=min(j, k); l++) {
                    dp[i][j] += dp[i-1][j-l];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[n][target];
    }
};

