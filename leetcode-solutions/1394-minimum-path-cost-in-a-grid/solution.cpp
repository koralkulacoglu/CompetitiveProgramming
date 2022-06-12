class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int i=0; i<m; i++) dp[0][i] = grid[0][i];
        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int k=0; k<m; k++) {
                    // go from k to j
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
                }
            }
        }
        int ans=1e9;
        for (int i=0; i<m; i++) ans = min(ans, dp[n-1][i]);
        return ans;
    }
};
