class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for (int i=1; i<=n; i++) {
            int maxA=0, ans=0;
            for (int j=1; j<=k && i-j>=0; j++) {
                maxA = max(maxA, arr[i-j]);
                ans = max(ans, dp[i-j] + maxA*j);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
