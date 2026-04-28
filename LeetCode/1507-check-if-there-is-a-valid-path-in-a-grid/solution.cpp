class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> vis;

bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (x == n - 1 && y == m - 1) return true;
        
        visited[x][y] = true;
        int val = grid[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            
            int newVal = grid[nx][ny];

            if (i == 0) {
                if ((val == 2 || val == 5 || val == 6) && (newVal == 2 || newVal == 3 || newVal == 4)) {
                    if (dfs(nx, ny, grid, visited)) return true;
                }
            }
            else if (i == 1) {
                if ((val == 2 || val == 3 || val == 4) && (newVal == 2 || newVal == 5 || newVal == 6)) {
                    if (dfs(nx, ny, grid, visited)) return true;
                }
            }
            else if (i == 2) {
                if ((val == 1 || val == 3 || val == 5) && (newVal == 1 || newVal == 4 || newVal == 6)) {
                    if (dfs(nx, ny, grid, visited)) return true;
                }
            }
            else if (i == 3) {
                if ((val == 1 || val == 4 || val == 6) && (newVal == 1 || newVal == 3 || newVal == 5)) {
                    if (dfs(nx, ny, grid, visited)) return true;
                }
            }
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dfs(0, 0, grid, visited);
    }
};
