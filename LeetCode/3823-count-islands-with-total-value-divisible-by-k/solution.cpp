class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> a;
    vector<vector<bool>> vis;
    int n, m, MOD;
    int dfs(int x, int y) {
        int val = a[x][y] % MOD;
        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            if (a[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            val += dfs(nx, ny);
            val %= MOD;
        }
        return val;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        MOD = k;
        vis.resize(n, vector<bool>(m, false));
        a = grid;
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    vis[i][j] = true;
                    ans += dfs(i, j) == 0;
                }
            }
        }
        return ans;
    }
};
