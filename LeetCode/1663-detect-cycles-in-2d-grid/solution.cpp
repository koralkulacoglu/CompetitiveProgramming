class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<bool>> vis;
    int n, m;

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = true;

        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx == px && ny == py) continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            if (vis[nx][ny]) return true;
            
            if (dfs(nx, ny, x, y, grid)) return true;
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (vis[i][j]) continue;
                if (dfs(i, j, -1, -1, grid)) return true;
            }
        }
        return false;
    }
};
