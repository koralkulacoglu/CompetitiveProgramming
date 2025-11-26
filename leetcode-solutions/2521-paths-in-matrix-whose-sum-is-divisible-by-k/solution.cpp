class Solution {
    int MOD = 1e9+7;

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0]%k] = 1;

        int sum = grid[0][0]%k;
        for (int j=1; j<m; j++) {
            sum += grid[0][j];
            sum %= k;
            dp[0][j][sum]++;
        }

        sum = grid[0][0]%k;
        for (int i=1; i<n; i++) {
            sum += grid[i][0];
            sum %= k;
            dp[i][0][sum]++;
        }

        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                for (int c=0; c<k; c++) {
                    int rem = (c + grid[i][j]) % k;

                    dp[i][j][rem] += dp[i-1][j][c];
                    dp[i][j][rem] %= MOD;
                    dp[i][j][rem] += dp[i][j-1][c];
                    dp[i][j][rem] %= MOD;

                    // cout << "i=" << i << ", j=" << j << ", rem=" << rem << ", dp[i][j][rem]=" << dp[i][j][rem] << endl;
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
