class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int i=0; i<m; i++) dp[0][i] = a[0][i];
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<m; j++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i+1][j]);
                if (j+1<m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + a[i+1][j+1]);
                if (j-1>=0) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + a[i+1][j-1]);
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
