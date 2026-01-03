class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(k+1, vector<long long>(3, -1e9)); // neither, long, short
        dp[0][0] = 0;
        long long ans = 0;
        for (int price : prices) {
            for (int t=k; t>0; t--) {
                dp[t][0] = max(dp[t][0], dp[t][0]);
                dp[t][0] = max(dp[t][0], dp[t][1] + price);
                dp[t][0] = max(dp[t][0], dp[t][2] - price);

                dp[t][1] = max(dp[t][1], dp[t-1][1]);
                dp[t][1] = max(dp[t][1], dp[t-1][0] - price);

                dp[t][2] = max(dp[t][2], dp[t-1][2]);
                dp[t][2] = max(dp[t][2], dp[t-1][0] + price);

                ans = max(ans, dp[t][0]);
            }
        }

        return ans;
    }
};
