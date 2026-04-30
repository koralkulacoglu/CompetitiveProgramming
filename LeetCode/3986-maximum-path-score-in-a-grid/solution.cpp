class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1e9)));
        if (grid[0][0]) dp[0][0][1] = grid[0][0];
        else dp[0][0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int cost = grid[i][j] != 0;
                for (int l=cost; l<=k; l++) {
                    if (i > 0) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l-cost] + grid[i][j]);
                    if (j > 0) dp[i][j][l] = max(dp[i][j][l], dp[i][j-1][l-cost] + grid[i][j]);
                }
            }
        }
        int ans = *max_element(dp[n-1][m-1].begin(), dp[n-1][m-1].end());
        return (ans >= 0 ? ans : -1);
    }
};
