class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, 1e18);
        dp[0] = 0;
        for (int i=0; i<=amount; i++) {
            for (int j : coins) {
                if (i-j >= 0) dp[i] = min(dp[i], dp[i-j]+1);
            }
        }

        return dp[amount] < 1e15 ? dp[amount] : -1;
    }
};
