class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        dp[0][0][grid[0][0]] = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i > 0) {
                    for (int k=0; k<1024; k++) {
                        if (!dp[i-1][j][k]) continue;
                        dp[i][j][grid[i][j] ^ k] = true;
                    }
                }
                if (j > 0) {
                    for (int k=0; k<1024; k++) {
                        if (!dp[i][j-1][k]) continue;
                        dp[i][j][grid[i][j] ^ k] = true;
                    }
                }
            }
        }
        int ans = 1e9;
        for (int k=0; k<1024; k++) {
            if (dp[n-1][m-1][k]) ans = min(ans, k);
        }
        return ans;
    }
};
