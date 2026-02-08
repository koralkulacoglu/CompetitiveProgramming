class Solution {
    long long MOD = 1e18;
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount+1, 0); dp[0] = 1;
        for (int j=0; j<n; j++) {
            for (int i=coins[j]; i<=amount; i++) {
                if (i - coins[j] < 0) continue;
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
        return dp[amount];
    }
};

