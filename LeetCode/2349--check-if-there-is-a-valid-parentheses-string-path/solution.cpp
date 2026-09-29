class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')') return false;
        int n = grid.size();
        int m = grid[0].size();
        auto cost = [](char c) { return c == '(' ? 1 : -1; };
        auto isValid = [&](int x) { return x >= 0 && x <= n + m; };
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n+m+1, false)));
        dp[0][0][1] = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                for (int k=0; k<=n+m; k++) {
                    int c = cost(grid[i][j]);
                    if (!isValid(k - c)) continue;
                    if (i > 0) dp[i][j][k] |= dp[i-1][j][k - c];
                    if (j > 0) dp[i][j][k] |= dp[i][j-1][k - c];
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};
