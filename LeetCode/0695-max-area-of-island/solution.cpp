class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> a;
    vector<vector<bool>> vis;

    int n, m, ans, cur;
    void dfs(int x, int y) {
        cur++;
        vis[x][y] = true;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && a[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        a = grid;
        n=a.size(), m=a[0].size();
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        
        ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) {
                    cur = 0;
                    dfs(i, j);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
