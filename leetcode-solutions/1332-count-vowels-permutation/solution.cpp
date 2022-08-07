class Solution {
public:
    long long MOD = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5, 0)); // a e i o u
        for (int i=0; i<5; i++) dp[0][i] = 1;
        for (int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + dp[i-1][2];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4];
            dp[i][3] = dp[i-1][2] + dp[i-1][4];
            dp[i][4] = dp[i-1][0];
            for (int j=0; j<5; j++) dp[i][j] %= MOD;
        }
        long long ans = 0;
        for (int i=0; i<5; i++) {
            ans += dp[n-1][i];
            ans %= MOD;
        }
        return ans;
    }
};
