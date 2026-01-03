class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i=0; i<n; i++) {
            if (grid[i][0]) break;
            dp[i][0] = 1;
        }
        for (int j=0; j<m; j++) {
            if (grid[0][j]) break;
            dp[0][j] = 1;
        }
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (!grid[i][j]) dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
