class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> vals;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) vals.push_back({i, j});

        sort(vals.begin(), vals.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            int valA = matrix[a.first][a.second];
            int valB = matrix[b.first][b.second];
            return valA < valB;
        });

        vector<vector<int>> dp(n, vector<int>(m, 0));

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        int ans = 0;

        for (auto& val : vals) {
            int x = val.first;
            int y = val.second;

            dp[x][y] = 1;

            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (matrix[nx][ny] >= matrix[x][y]) continue;

                dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
            }

            ans = max(ans, dp[x][y]);
        }

        return ans;
    }
};
