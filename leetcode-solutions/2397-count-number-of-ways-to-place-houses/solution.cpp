class Solution {
public:
    int MOD = 1e9+7;

    int countHousePlacements(int n) {
        vector<long long> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= MOD;
        }
        // for (long long &i : dp) cout << i << ' ';
        // cout << '\n';
        return (dp[n]*dp[n])%MOD;
    }
};
