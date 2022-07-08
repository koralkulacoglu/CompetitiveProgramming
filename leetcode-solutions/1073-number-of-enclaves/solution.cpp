class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> a;
    vector<vector<bool>> vis;

    int n, m, ans, cur;
    bool dfs(int x, int y) {
        cur++;
        vis[x][y] = true;
        bool res=true;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && a[nx][ny]) {
                if (!dfs(nx, ny)) {
                    res = false;
                }
            }
        }
        if (x==n-1 || x==0 || y==m-1 || y==0) {
            return false;
        }
        return res;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        a = grid;
        n=a.size(), m=a[0].size();
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cur = 0;
                if (a[i][j] && !vis[i][j] && dfs(i, j)) {
                    ans += cur;
                }
            }
        }
        return ans;
    }
};
