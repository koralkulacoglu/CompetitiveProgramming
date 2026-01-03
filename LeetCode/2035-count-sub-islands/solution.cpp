class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> a, b;
    vector<vector<bool>> vis;
    int n, m;
    bool dfs(int x, int y) {
        vis[x][y] = true;
        bool wk = a[x][y];
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && b[nx][ny]) {
                if (!dfs(nx, ny)) {
                    wk = false;
                }
            }
        }
        return wk;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        a = grid1;
        b = grid2;
        n = a.size();
        m = a[0].size();
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && b[i][j] && dfs(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
