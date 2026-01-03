class Solution {
public:
    int n, m;
    vector<vector<int>> vals;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    int dfs(int x, int y, int rem, vector<vector<bool>> vis) {
        if (vals[x][y] == 2) return !rem;
        
        vis[x][y] = true;
        int ans=0;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < n && nx >= 0 && ny < m && ny >= 0 && !vis[nx][ny] && vals[nx][ny] != -1) {
                ans += dfs(nx, ny, rem-1, vis);
            }
        }
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vals = grid;
        
        int x, y;
        int rem=n*m-1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                rem -= (vals[i][j] == -1);
                if (vals[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return dfs(x, y, rem, vis);
    }
};
